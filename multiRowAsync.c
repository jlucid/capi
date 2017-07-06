/* File name: multiRowAsync.c */
#include "common.h"

int main() {
  J i, n= 3;
  I handle;
  I portnumber= 5010;
  S hostname= "localhost";
  S usernamePassword= "kdb:pass";
  S symbols[]= { "ABC", "DEF", "GHI" };
  K result;

  handle= khpu(hostname, portnumber, usernamePassword);
  if(!handleOk(handle))
    return EXIT_FAILURE;

  K multipleRow= knk(3, ktn(KS, n), ktn(KF, n), ktn(KJ, n));
  for(i= 0; i < n; i++) {
    kS(kK(multipleRow)[0])[i]= ss(symbols[i % n]);
    kF(kK(multipleRow)[1])[i]= 10.0 * i;
    kJ(kK(multipleRow)[2])[i]= i;
  }

  // Perform multiple row insert asynchronously, tickerplant will add timestamp
  // column itself
  result= k(-handle, ".u.upd", ks((S) "trade"), multipleRow, (K) 0);
  if(isRemoteErr(result)) {
    kclose(handle);
    return EXIT_FAILURE;
  }

  kclose(handle);
  return EXIT_SUCCESS;
}
