#include<stdio.h>
#include"k.h"

int main()
{
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K list;

    handle = khpu(hostname,portnumber,usernamePassword);

    list = k(handle,"2*1 2 3f",(K)0);
    printf("List length is %lld\n",list->n);

    kclose(handle);
    return 0;
}
