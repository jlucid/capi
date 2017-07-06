/* File name: table.c */
#include"common.h"

int main()
{
    J i;
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K table,columns,values,col1,col2;

    handle = khpu(hostname,portnumber,usernamePassword);
    if(!handleOk(handle))
        return EXIT_FAILURE;
         
    // Execute a query which performs an aggregate on table t
    // Table t can be defined on the q process as follows
    // q)t:([] sym:`a`a`b`b`c`c;price:1.0 2.0 3.0 4.0 5.0 6.0)
    table = k(handle,"select from t where price=(max;price) fby sym",(K)0);
    if(isRemoteErr(table)){
        kclose(handle);
        return EXIT_FAILURE;
    }

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

    for(i=0; i<col1->n; i++)
        {
            printf("%s %lf\n",kS(col1)[i],kF(col2)[i]);
        }

    r0(table);
    kclose(handle);
    return EXIT_SUCCESS;
}
