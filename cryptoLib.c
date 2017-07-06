/* File name: cryptoLib.c */
#include<stdlib.h>
#include<string.h>
#include<openssl/md5.h>
#include<openssl/sha.h>
#include "k.h"

K md5(K inputString)
{
    if(KC!=inputString->t)
        {
            return krr("type");
        }

    J i,numBytes = MD5_DIGEST_LENGTH;
    unsigned char output[numBytes];
    K outputHash = ktn(KG , numBytes);

    MD5(kC(inputString), inputString->n, output);

    for(i=0; i<numBytes; i++)
        {
            kG(outputHash)[i] = output[i];
        }
    return outputHash;
}

K sha256(K inputString)
{
    if(KC!=inputString->t)
        {
            return krr("type");
        }

    J i,numBytes = SHA256_DIGEST_LENGTH;
    unsigned char output[numBytes];
    K outputHash = ktn(KG , numBytes);

    SHA256(kC(inputString), inputString->n, output);

    for(i=0; i<numBytes; i++)
        {
            kG(outputHash)[i] = output[i];
        }
    return outputHash;
}


K sha512(K inputString)
{
    if(KC!=inputString->t)
        {
            return krr("type");
        }

    J i,numBytes = SHA512_DIGEST_LENGTH;
    unsigned char output[numBytes];
    K outputHash = ktn(KG , numBytes);

    SHA512(kC(inputString), inputString->n, output);

    for(i=0; i<numBytes; i++)
        {
            kG(outputHash)[i] = output[i];
        }
    return outputHash;
}




