/* File name: portopen.c */
#include<stdio.h>
#include"k.h"
// Note that error capture has been removed
// Will be covered in later examples
int main()
{
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";

    handle = khpu(hostname,portnumber,usernamePassword);

    if(handle==0)
        {
            printf("Authentication error %d\n",handle);
            return 0;
        }

    if(handle==-1)
        {
            printf("Connection error %d\n",handle);
            return 0;
        }

    printf("Handle value is %d\n",handle);

    kclose(handle);
    return 0;
}
