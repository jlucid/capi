#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include "k.h"

J castTime(struct tm *x)
{
    return (J) ((60*x->tm_hour+x->tm_min)*60 + x->tm_sec)*1000000000;
}

int main()
{
    int i,n = 3;
    I handle;
    I portnumber = 5010;
    S hostname = "localhost";
    K result;
    S usernamePassword = "kdb:pass";
    S symbols[]= {"ABC","DEF","GHI"};
    time_t currentTime;
    struct tm *ct;

    handle = khpu(hostname, portnumber, usernamePassword);

    K multipleRow=knk(4,ktn(KN,n),ktn(KS,n),ktn(KF,n),ktn(KJ,n));
    time( &currentTime );
    ct = localtime( &currentTime );

    for(i=0; i<n; i++)
        {
            kJ(kK(multipleRow)[0])[i] = castTime(ct);
            kS(kK(multipleRow)[1])[i] = ss(symbols[i%n]);
            kF(kK(multipleRow)[2])[i] = 10.0*i;
            kJ(kK(multipleRow)[3])[i] = i;
        }
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
