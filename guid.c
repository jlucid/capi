/* File name: guid.c */
#include<stdio.h>
#include"k.h"

int main()
{
    int i,j;
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K singleGuid,multiGuid;

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

    singleGuid = k(handle,"rand 0Ng",(K)0);

    if(!singleGuid)
        {
            perror("Network Error\n");
            return 0;
        }

    if(-128==singleGuid->t)
        {
            printf("Error message returned : %s\n",singleGuid->s);
            r0(singleGuid);
	    return 0;
        }

    printf("Single guid: type %d\n",singleGuid->t);
    printf("Single guid: length %lld\n",singleGuid->n);

    for(i=0; i<16; i++)
        {
            printf("%02x",kU(singleGuid)->g[i]);
        }
    printf("\n");

    multiGuid = k(handle,"2?0Ng",(K)0);

    if(!multiGuid)
        {
            perror("Network Error\n");
            return 0;
        }

    if(-128==multiGuid->t)
        {
            printf("Error message returned : %s\n",multiGuid->s);
            r0(multiGuid);
	    return 0;
        }

    printf("Multi guid: type %d\n",multiGuid->t);
    printf("Multi guid: length %lld\n",multiGuid->n);

    for(i=0; i<multiGuid->n; i++)
        {
            for(j=0; j<16; j++)
                {
                    printf("%02x",kU(multiGuid)[i].g[j]);
                }
            printf("\n");
        }

    r0(singleGuid);
    r0(multiGuid);
    kclose(handle);
    return 0;
}
