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
    S usernamePassword="kdb:pass",symbols[]= {"ABC","DEF","GHI"};
    K result;

    handle = khpu(hostname, portnumber, usernamePassword);

    while(1)
        {
            sleep(1);
            K multipleRow = knk(3, ktn(KS,n), ktn(KF,n), ktn(KI,n));
            for(i=0; i<n; i++)
                {
                    kS(kK(multipleRow)[0])[i] = ss(symbols[i%n]);
                    kF(kK(multipleRow)[1])[i] = 10.0*i;
                    kI(kK(multipleRow)[2])[i] = i;
                }
            result = k(handle,".u.upd",ks((S)"trade"),multipleRow,(K)0);
        }

    kclose(handle);
    return 0;
}
