#include<stdio.h>
#include"k.h"
#include"time.h"

void castTime(int t)
{
    time_t timval=t/1000;
    struct tm *timinfo=localtime(&timval);
    printf("%02d:%02d:%02d.%03d",
           timinfo->tm_hour,
           timinfo->tm_min,
           timinfo->tm_sec,
           t%1000
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
                    if(response->t== 0)
                        {
                            table = kK(response)[2]->k;
                            columnNames  = kK(table)[0];
                            columnValues = kK(table)[1];
                            printf(" time sym price size\n");
                            printf(" -----------------------------\n");

                            for(i=0; i<kK(columnValues)[0]->n; i++)
                                {
                                    castTime(kI(kK(columnValues)[0])[i]);
                                    printf("%s ",  kS(kK(columnValues)[1])[i]);
                                    printf("%lf ", kF(kK(columnValues)[2])[i]);
                                    printf("%d \n",kI(kK(columnValues)[3])[i]);
                                }
                        }
                }
            r0(response);
        }

    kclose(handle);
    return 0;
}

