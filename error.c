#include<stdio.h>
#include"k.h"

int main ()
{
    K result;
    I port  =  12345;
    I timeout  = 5000;
    I handle;

    handle =  khpun("localhost",port,"kdb:pass",timeout);

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

    if(handle==-2)
        {
            printf("Time out error %d\n",handle);
            return 0;
        }

    result =  k(handle,"1+`2",(K)0);
    if(-128==result->t)
        {
            printf("Error message returned : %s\n",result->s);
        }

    result =  k(handle,"`a`b`c=`a`b",(K)0);
    if(-128== result->t)
        {
            printf("Error message returned : %s\n",result->s);
        }

    result =  k(handle,"select sym t :([] sym:`a`b)",(K)0);
    if (-128== result->t)
        {
            printf("Error message returned : %s\n",result->s);
        }

    kclose(handle);
    return 0;
}
