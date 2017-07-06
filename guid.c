/* File name: guid.c */
#include"common.h"

int main()
{
    J i,j;
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K singleGuid,multiGuid;

    handle = khpu(hostname,portnumber,usernamePassword);
    if(!handleOk(handle))
        return EXIT_FAILURE;

    singleGuid = k(handle,"rand 0Ng",(K)0);
    if(isRemoteErr(singleGuid)){
        kclose(handle);
        return EXIT_FAILURE;
    }

    printf("Single guid: type %d\n",singleGuid->t);
    printf("Single guid: length %lld\n",singleGuid->n);

    for(i=0; i<16; i++)
        {
            printf("%02x",kU(singleGuid)->g[i]);
        }
    r0(singleGuid);
    printf("\n");

    multiGuid = k(handle,"2?0Ng",(K)0);
    if(isRemoteErr(multiGuid)){
        kclose(handle);
        return EXIT_FAILURE;
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
    r0(multiGuid);
    kclose(handle);
    return EXIT_SUCCESS;
}
