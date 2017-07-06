/* File name: refcountk.c */
#include "common.h"

int main() {
  I handle;
  I portnumber= 12345;
  S hostname= "localhost";
  S usernamePassword= "kdb:pass";
  K response, a;
  // NOTE: connection must be opened before creating K objects
  handle= khpu(hostname, portnumber, usernamePassword);
  if(!handleOk(handle))
    return EXIT_FAILURE;

  a= ki(5);
  printf("ref count of a is %d\n", a->r);
  printf("int value of a is %d\n", a->i);

  response= k(handle, "{x+3i}", a, (K) 0);
  // it is illigal to access a after this call as object has been destroyed

  if(isRemoteErr(response)) {
    kclose(handle);
    return EXIT_FAILURE;
  }

  printf("response value is %d\n", response->i);

  r0(response);
  kclose(handle);
  return EXIT_SUCCESS;
}
