#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include "k.h"

I castTime(struct tm *x)
{
    return (I) ((60*x->tm_hour+x->tm_min)*60 + x->tm_sec)*1000;
};

int main()
{
    int i,n = 3;
    I handle;
    I portnumber = 5010;
    S hostname = "localhost";
    K result;
    S usernamePassword="kdb:pass",symbols[]= {"ABC","DEF","GHI"};
    time_t currentTime;
    struct tm *ct;

    handle = khpu(hostname, portnumber, usernamePassword);

    while(1)
        {
            sleep(1);
            K multipleRow=knk(4,ktn(KT,n),ktn(KS,n),ktn(KF,n),ktn(KI,n));
            time( &currentTime );
            ct = localtime( &currentTime );

            for(i=0; i<n; i++)
                {
                    kI(kK(multipleRow)[0])[i] = castTime(ct);
                    kS(kK(multipleRow)[1])[i] = ss(symbols[i%n]);
                    kF(kK(multipleRow)[2])[i] = 10.0*i;
                    kI(kK(multipleRow)[3])[i] = i;
                }
            result = k(handle,".u.upd",ks((S)"trade"),multipleRow,(K)0);
        }

    kclose(handle);
    return 0;
}
