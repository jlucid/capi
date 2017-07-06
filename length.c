/* File name: length.c */
#include"common.h"

int main()
{
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K list;

    handle = khpu(hostname,portnumber,usernamePassword);
    if(!handleOk(handle))
        return EXIT_FAILURE;

    list = k(handle,"2*1 2 3f",(K)0);
    if(isRemoteErr(list)){
        kclose(handle);
        return EXIT_FAILURE;
    }

    printf("List length is %lld\n",list->n);

    r0(list);
    kclose(handle);
    return EXIT_SUCCESS;
}
