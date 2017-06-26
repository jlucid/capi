#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "k.h"

int main()
{
    I handle;
    I portnumber = 5010;
    S hostname = "localhost";
    S usernamePassword = "kdb:pass";
    K result,singleRow;

    handle = khpu(hostname,portnumber,usernamePassword);

    while(1)
        {
            sleep(1);
            singleRow = knk(3,ks((S)"ABC"),kf(10.0), ki(20));
            result = k(handle,".u.upd", ks((S)"trade"),singleRow,(K)0);
        }

    kclose(handle);
    return 0;
}
