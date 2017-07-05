/* File name: refcountk.c */
#include<stdio.h>
#include"k.h"

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

    response = k(handle,"{x+3i}",a,(K)0);

    if(!response)
        {
            perror("Network Error\n");
            return 0;
        }

    if(-128==response->t)
        {
            printf("Error message returned : %s\n",response->s);
            r0(response);
	    return 0;
        }
   
    printf("response value is %d\n", response->i);
    printf("value of a is now %d\n", a->i);
    
    r0(response);
    kclose(handle);
    return 0;
}
