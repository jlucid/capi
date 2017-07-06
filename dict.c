/* File name: dict.c */
#include "common.h"

int main() {
  J i;
  I handle;
  I portnumber= 12345;
  S hostname= "localhost";
  S usernamePassword= "kdb:pass";
  K x, keys, values;

  handle= khpu(hostname, portnumber, usernamePassword);

  if(!handleOk(handle))
    return EXIT_FAILURE;

  x= k(handle, "`a`b`c!((1;2;3);(10.0;20.0);(`AB`CD`EF`GH))", (K) 0);

  if(isRemoteErr(x)) {
    kclose(handle);
    return EXIT_FAILURE;
  }

  printf("Dict type = %d\n", x->t);
  printf("Num elements = %lld (keys and values)\n", x->n);

  keys= kK(x)[0];
  values= kK(x)[1];

  printf("Keys type = %d\n", keys->t);
  printf("Num keys = %lld\n", keys->n);

  printf("Values type = %d\n", values->t);
  printf("Num values = %lld\n", values->n);

  for(i= 0; i < keys->n; i++) {
    printf("keys[%lld] = %s\n", i, kS(keys)[i]);
  }

  for(i= 0; i < values->n; i++) {
    printf("values[%lld] has length %lld\n", i, kK(values)[i]->n);
  }

  J *values0= kJ(kK(values)[0]);
  F *values1= kF(kK(values)[1]);
  S *values2= kS(kK(values)[2]);

  printf("values[0;] = %lld %lld %lld\n", values0[0], values0[1], values0[2]);
  printf("values[1;] = %lf %lf       \n", values1[0], values1[1]);
  printf("values[2;] = %s %s %s %s   \n", values2[0], values2[1], values2[2],
         values2[3]);

  r0(x);
  kclose(handle);
  return EXIT_SUCCESS;
}
