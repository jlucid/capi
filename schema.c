/* File name: schema.c */
#include<stdio.h>
#include"k.h"
// Note that error capture has been removed
int main()
{
    int i;
    I handle;
    I portnumber = 5010;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K response, table, columnNames;

    handle = khpu(hostname,portnumber,usernamePassword);
    response = k(handle,".u.sub[`trade;`]",(K)0);

    // .u.sub returns a two element list
    // containing the table name and schema
    // q)h:hopen 12345
    // q)h".u.sub[`trade;`]"
    // `trade
    // +`time`sym`price`size!(();();();())
    printf("Number of elements returned is %lld\n",response->n);
    printf("Table name: %s\n",kK(response)[0]->s);

    table = kK(response)[1]->k;
    columnNames = kK(table)[0];

    printf("Num colNames: %lld\n",columnNames->n);
    for(i=0; i<columnNames->n; i++)
        {
            printf("Column %d is named %s\n",i,kS(columnNames)[i]);
        }

    r0(response);
    kclose(handle);
    return 0;
}
