/* File name: mixedList.c */
#include"common.h"

int main()
{
    J i;
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K mixedList,elementOne,elementTwo;

    handle = khpu(hostname,portnumber,usernamePassword);
    if(!handleOk(handle))
        return EXIT_FAILURE;

    mixedList = k(handle,"(1 2 3 4 5;20.0 30.0 40.0)",(K)0);
    if(isRemoteErr(mixedList)){
        kclose(handle);
        return EXIT_FAILURE;
    }

    printf("Object mixed list type: %d\n",mixedList->t);
    printf("Mixed list contains %lld elements\n",mixedList->n);

    elementOne = kK(mixedList)[0];
    elementTwo = kK(mixedList)[1];

    printf("elementOne contains %lld elements\n",elementOne->n);
    printf("elementTwo contains %lld elements\n",elementTwo->n);

    for(i=0; i<elementOne->n; i++)
        {
            printf("elementOne[%lld] = %lld\n",i, kJ(elementOne)[i]);
        }

    for(i=0; i<elementTwo->n; i++)
        {
            printf("elementTwo[%lld] = %f\n",i, kF(elementTwo)[i]);
        }

    r0(mixedList);
    kclose(handle);
    return EXIT_SUCCESS;
}
