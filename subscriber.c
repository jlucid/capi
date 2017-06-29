/* File name: subscriber.c */
#include<stdio.h>
#include"k.h"
#include"time.h"

void printTime(long long t)
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
    int i;
    I handle;
    I portnumber = 5010;
    S hostname = "localhost";
    S usernamePassword = "kdb:pass";
    K response,table,columnNames,columnValues;

    handle = khpu(hostname,portnumber,usernamePassword);
    response = k(handle,".u.sub[`trade;`]",(K)0);

    while(1)
        {
            response = k(handle,(S)0);
            if(response)
                {
                    if(response->t==0 && response->n>=3)
                        {
                            table = kK(response)[2]->k;
                            columnNames  = kK(table)[0];
                            columnValues = kK(table)[1];
                            printf(" time sym price size\n");
                            printf(" -----------------------------\n");

                            for(i=0; i<kK(columnValues)[0]->n; i++)
                                {
                                    printTime(kJ(kK(columnValues)[0])[i]);
                                    printf("%s ",  kS(kK(columnValues)[1])[i]);
                                    printf("%lf ", kF(kK(columnValues)[2])[i]);
                                    printf("%lld \n",kJ(kK(columnValues)[3])[i]);
                                }
                        }
                }
            r0(response);
        }

    kclose(handle);
    return 0;
}

