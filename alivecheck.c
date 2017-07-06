/* File name: alivecheck.c */
#include "common.h"

int main() {
  I handle;
  I portnumber= 12345;
  S hostname= "localhost";
  S usernamePassword= "kdb:pass";
  K result;

  handle= khpu(hostname, portnumber, usernamePassword);
  if(!handleOk(handle))
    return EXIT_FAILURE;
  printf("Handle value is %d\n", handle);
  result= k(handle, "2.0+3.0", (K) 0);
  if(isRemoteErr(result)) {
    kclose(handle);
    return EXIT_FAILURE;
  }
  printf("Value returned is %f\n", result->f);

  r0(result);
  kclose(handle);
  return EXIT_SUCCESS;
}
