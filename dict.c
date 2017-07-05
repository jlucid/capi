/* File name: dict.c */
#include<stdio.h>
#include"k.h"

int main()
{
    int i;
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K x,keys,values;

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

    x = k(handle,"`a`b`c!((1;2;3);(10.0;20.0);(`AB`CD`EF`GH))",(K)0);

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

    printf("Dict type = %d\n",x->t);
    printf("Num elements = %lld (keys and values)\n",x->n);

    keys   = kK(x)[0];
    values = kK(x)[1];

    printf("Keys type = %d\n",keys->t);
    printf("Num keys = %lld\n",keys->n);

    printf("Values type = %d\n",values->t);
    printf("Num values = %lld\n",values->n);

    for(i=0; i<keys->n; i++)
        {
            printf("keys[%d] = %s\n",i,kS(keys)[i]);
        }

    for(i=0; i<values->n; i++)
        {
            printf("values[%d] has length %lld\n",i,kK(values)[i]->n);
        }

    J* values0 = kJ(kK(values)[0]);
    F* values1 = kF(kK(values)[1]);  
    S* values2 = kS(kK(values)[2]);  
 
    printf("values[0;] = %lld %lld %lld\n",values0[0],values0[1],values0[2]);
    printf("values[1;] = %lf %lf       \n",values1[0],values1[1]);
    printf("values[2;] = %s %s %s %s   \n",values2[0],values2[1],values2[2],values2[3]);

    r0(x);
    r0(keys);
    kclose(handle);
    return 0;
}
