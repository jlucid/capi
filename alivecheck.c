/* File name: alivecheck.c */
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
    result = k(handle,"2.0+3.0",(K)0);

    if(!result)
        {
            perror("Network Error\n");
            return 0;
        }

    if(-128==result->t)
        {
            printf("Error message returned : %s\n",result->s);
            r0(result);
	    return 0;
        }

    printf("Value returned is %f\n",result->f);

    r0(result);
    kclose(handle);
    return 0;
}
