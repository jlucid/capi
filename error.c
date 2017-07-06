/* File name: error.c */
#include "common.h"

int main() {
  K result;
  I port= 12345;
  I timeout= 5000;
  I handle;

  handle= khpun("localhost", port, "kdb:pass", timeout);
  if(!handleOk(handle))
    return EXIT_FAILURE;

  result= k(handle, "1+`2", (K) 0);
  // Handle network error
  if(!result) {
    perror("Network Error\n");
    kclose(handle);
    return EXIT_FAILURE;
  }

  if(-128 == result->t) {
    fprintf(stderr, "Error message returned : %s\n", result->s);
  }
  r0(result);

  result= k(handle, "`a`b`c=`a`b", (K) 0);
  // Handle network error
  if(!result) {
    perror("Network Error\n");
    kclose(handle);
    return EXIT_FAILURE;
  }
  if(-128 == result->t) {
    fprintf(stderr, "Error message returned : %s\n", result->s);
  }
  r0(result);

  result= k(handle, "select sym t :([] sym:`a`b)", (K) 0);
  // Handle network error
  if(!result) {
    perror("Network Error\n");
    kclose(handle);
    return EXIT_FAILURE;
  }
  if(-128 == result->t) {
    fprintf(stderr, "Error message returned : %s\n", result->s);
  }
  r0(result);

  kclose(handle);
  return EXIT_SUCCESS;
}
