#include<stdio.h>
#include"k.h"


int main()
{
    int i;
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K response, table, columnNames;

    handle = khpu(hostname,portnumber,usernamePassword);
    response = k(handle,"0#trade",(K)0);

    printf("Number of elements returned is %lld\n",response->n);
    printf("Table name: %s\n",kK(response)[0]->s);

    table = kK(response)[1]->k;
    columnNames = kK(table)[0];

    printf("Num colNames: %lld\n",columnNames->n);
    for(i=0; i<columnNames->n; i++)
        {
            printf("Column %d is named %s\n",i,kS(columnNames)[i]);
        }

    kclose(handle);
    return 0;
}

