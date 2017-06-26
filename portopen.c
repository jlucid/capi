#include<stdio.h>
#include"k.h"

int main()
{
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";

    handle = khpu(hostname,portnumber,usernamePassword);
    printf("Handle value is %d\n",handle);

    kclose(handle);
    return 0;
}
