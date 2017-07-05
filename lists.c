/* File name: lists.c */
#include<stdio.h>
#include"k.h"

int main()
{
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K x;

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

    x = k(handle,"reverse `A`B`C",(K)0);

    if(!x)
        {
            perror("Network Error\n");
            return 0;
        }

    if(-128==x->t)
        {
            printf("Error message returned : %s\n",x->s);
            r0(x);
	    return 0;
        }

    printf("Symbols: %s %s %s\n",kS(x)[0],kS(x)[1],kS(x)[2]);

    x = k(handle,"reverse 1 2 3",(K)0);

    if(!x)
        {
            perror("Network Error\n");
            return 0;
        }

    if(-128==x->t)
        {
            printf("Error message returned : %s\n",x->s);
            r0(x);
	    return 0;
        }

    printf("Ints: %lld %lld %lld\n",kJ(x)[0],kJ(x)[1],kJ(x)[2]);

    x = k(handle,"reverse 1.0 2.0 3.0",(K)0);

    if(!x)
        {
            perror("Network Error\n");
            return 0;
        }

    if(-128==x->t)
        {
            printf("Error message returned : %s\n",x->s);
            r0(x);
	    return 0;
        }

    printf("Floats: %f %f %f\n",kF(x)[0],kF(x)[1],kF(x)[2]);

    r0(x);    
    kclose(handle);
    return 0;
}
