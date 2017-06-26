#include<stdio.h>
#include"k.h"

int main()
{
    int iter=0;
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K table,columns,values,col1,col2;

    handle = khpu(hostname,portnumber,usernamePassword);

    // Execute a query on table t which returns a simple table
    table = k(handle,"select from t where price=(max;price) fby sym",(K)0);

    // Extract columns and values elements
    columns = kK(table->k)[0];
    values  = kK(table->k)[1];

    //Show column count and print column names
    printf("Number of Columns = %lld\n",columns->n);
    printf("Columns: %s %s\n",kS(columns)[0],kS(columns)[1]);

    //Access the table values
    printf("values object has type = %d\n",values->t);

    col1 = kK(values)[0];
    col2 = kK(values)[1];

    printf("Number of elements in column 1 is %lld\n",col1->n);

    for(iter=0; iter<col1->n; iter++)
        {
            printf("%s %lf\n",kS(col1)[iter],kF(col2)[iter]);
        }

    kclose(handle);
    return 0;
}
