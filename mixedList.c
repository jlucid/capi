#include<stdio.h>
#include"k.h"
// Note that error capture has been removed
int main()
{
    int i;
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K mixedList,elementOne,elementTwo;

    handle = khpu(hostname,portnumber,usernamePassword);

    mixedList = k(handle,"(1 2 3 4 5;20.0 30.0 40.0)",(K)0);
    printf("Object mixed list type: %d\n",mixedList->t);
    printf("Mixed list contains %lld elements\n",mixedList->n);

    elementOne = kK(mixedList)[0];
    elementTwo = kK(mixedList)[1];

    printf("elementOne contains %lld elements\n",elementOne->n);
    printf("elementTwo contains %lld elements\n",elementTwo->n);

    for(i=0; i<elementOne->n; i++)
        {
            printf("elementOne[%d] = %lld\n",i, kJ(elementOne)[i]);
        }

    for(i=0; i<elementTwo->n; i++)
        {
            printf("elementTwo[%d] = %f\n",i, kF(elementTwo)[i]);
        }

    r0(mixedList);
    r0(elementOne);
    r0(elementTwo);
    kclose(handle);
    return 0;
}
