#include<stdio.h>
#include"k.h"

int main()
{
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K result;

    handle = khpu(hostname,portnumber,usernamePassword);
    result = k(handle,"2.0+3.0",(K)0);

    printf("Handle value is %d\n",handle);
    printf("Value returned is %f\n",result->f);

    r0(result);
    kclose(handle);
    return 0;
}
