/* File name: singleRow.c */
#include "common.h"

int main()
{
    I handle;
    I portnumber = 5010;
    S hostname = "localhost";
    S usernamePassword = "kdb:pass";
    K result,singleRow;

    handle = khpu(hostname,portnumber,usernamePassword);
    if(!handleOk(handle))
        return EXIT_FAILURE;

    singleRow = knk(3,ks((S)"ABC"),kf(10.0), kj(20));
    // Perform single row insert, tickerplant will add timestamp column itself
    result = k(handle,".u.upd", ks((S)"trade"),singleRow,(K)0);
    if(isRemoteErr(result)){
        kclose(handle);
        return EXIT_FAILURE;
    }

    r0(result);
    kclose(handle);
    return EXIT_SUCCESS;
}
