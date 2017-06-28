#include<stdio.h>
#include"k.h"
// Note that error capture has been removed
int main()
{
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K response,a;

    a = ki(5);
    printf("ref count of a is %d\n",a->r);
    printf("int value of a is %d\n",a->i);

    handle = khpu(hostname,portnumber,usernamePassword);
    response = k(handle,"{x+3i}",a,(K)0);
   
    printf("response value is %d\n", response->i);
    printf("value of a is now %d\n", a->i);
    kclose(handle);
    return 0;
}
