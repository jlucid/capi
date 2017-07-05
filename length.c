/* File name: length.c */
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

    list = k(handle,"2*1 2 3f",(K)0);

    if(!list)
        {
            perror("Network Error\n");
            return 0;
        }

    if(-128==list->t)
        {
            printf("Error message returned : %s\n",list->s);
            r0(list);
	    return 0;
        }

    printf("List length is %lld\n",list->n);

    r0(list);
    kclose(handle);
    return 0;
}
