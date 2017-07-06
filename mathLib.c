/* File name: mathLib.c */
#include <stdio.h>
#include "k.h"

K dotProduct(K x, K y) {
  J i;
  double result= 0.0;
  // Check data types are consistent
  if(x->t != KF || y->t != KF) {
    return krr("type");
  }

  // Check vector lengths are equal
  if(x->n != y->n) {
    return krr("length");
  }

  for(i= 0; i < x->n; i++) {
    result+= kF(x)[i] * kF(y)[i];
  }

  return kf(result);
}
