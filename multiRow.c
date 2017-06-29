/* File name: multiRow.c */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "k.h"

int main()
{
    int i,n = 3;
    I handle;
    I portnumber = 5010;
    S hostname = "localhost";
    S usernamePassword = "kdb:pass";
    S symbols[]= {"ABC","DEF","GHI"};
    K result;

    handle = khpu(hostname, portnumber, usernamePassword);

    K multipleRow = knk(3, ktn(KS,n), ktn(KF,n), ktn(KJ,n));
    for(i=0; i<n; i++)
        {
            kS(kK(multipleRow)[0])[i] = ss(symbols[i%n]);
            kF(kK(multipleRow)[1])[i] = 10.0*i;
            kJ(kK(multipleRow)[2])[i] = i;
        }

    // Perform multiple row insert, tickerplant will add timestamp column itself
    result = k(handle,".u.upd",ks((S)"trade"),multipleRow,(K)0);

    // Capture network error
    if(!result)
        {
            perror("Network Error\n");
        }

    // Capture error associated with failed insert
    if(-128==result->t)
        {
            printf("Error %s\n",result->s);
        }

    r0(result);
    kclose(handle);
    return 0;
}
