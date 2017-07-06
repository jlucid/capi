/* File name: cryptoLib.c */
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include "k.h"

K md5(K inputString) {
  K outputHash;
  if(KC != inputString->t)
    return krr("type");
  outputHash= ktn(KG, MD5_DIGEST_LENGTH);
  MD5(kC(inputString), inputString->n, kG(outputHash));
  return outputHash;
}

K sha256(K inputString) {
  K outputHash;
  if(KC != inputString->t)
    return krr("type");
  outputHash= ktn(KG, SHA256_DIGEST_LENGTH);
  SHA256(kC(inputString), inputString->n, kG(outputHash));
  return outputHash;
}

K sha512(K inputString) {
  K outputHash;
  if(KC != inputString->t)
    return krr("type");

  outputHash= ktn(KG, SHA512_DIGEST_LENGTH);
  SHA512(kC(inputString), inputString->n, kG(outputHash));
  return outputHash;
}
