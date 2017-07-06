/* File name: subscriber.c */
#include"common.h"
#include"time.h"

void printTime(J t)
{
    time_t timval=t/1000000000;
    struct tm *timeInfo=localtime(&timval);

    printf("%dD%02d:%02d:%02d.%09lld ",
           timeInfo->tm_yday,
           timeInfo->tm_hour,
           timeInfo->tm_min,
           timeInfo->tm_sec,
           t%1000000000
          );
}


int main()
{
    J i;
    I handle;
    I portnumber = 5010;
    S hostname = "localhost";
    S usernamePassword = "kdb:pass";
    K response,table,tableName,columnNames,columnValues;

    handle = khpu(hostname,portnumber,usernamePassword);
    if(!handleOk(handle))
        return EXIT_FAILURE;
    tableName = ks("trade");
    response = k(handle,".u.sub",r1(tableName),ks(""),(K)0);
    if(isRemoteErr(response)){
        r0(tableName);
        kclose(handle);
        return EXIT_FAILURE;
    }
    r0(response);
    while(1)
    {
        response = k(handle,(S)0);
        if(!response) break;

        if(response->t==0 
            && response->n>=3                       // check that we received 3 element list (`upd;`trade;table)
            && kK(response)[1]->t == -KS            // check that second element is a table name
            && kK(response)[1]->s == tableName->s   // check that table name is the one we subscribed to
            && kK(response)[2]->t == XT)
        {
            table = kK(response)[2]->k;
            columnNames  = kK(table)[0];
            columnValues = kK(table)[1];
            printf(" %s %s %s %s\n",
                kS(columnNames)[0],kS(columnNames)[1],
                kS(columnNames)[2],kS(columnNames)[3]);
            printf(" -----------------------------\n");

            for(i=0; i<kK(columnValues)[0]->n; i++)
            {
                printTime(kJ(kK(columnValues)[0])[i]);
                printf("%s ",  kS(kK(columnValues)[1])[i]);
                printf("%lf ", kF(kK(columnValues)[2])[i]);
                printf("%lld \n",kJ(kK(columnValues)[3])[i]);
            }
        }
        r0(response);
    }
    r0(tableName);
    kclose(handle);
    return EXIT_SUCCESS;
}

