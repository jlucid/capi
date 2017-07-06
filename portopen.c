/* File name: portopen.c */
#include "common.h"

int main() {
  I handle;
  I portnumber= 12345;
  S hostname= "localhost";
  S usernamePassword= "kdb:pass";

  handle= khpu(hostname, portnumber, usernamePassword);
  if(!handleOk(handle))
    return EXIT_FAILURE;

  printf("Handle value is %d\n", handle);

  kclose(handle);
  return EXIT_SUCCESS;
}
