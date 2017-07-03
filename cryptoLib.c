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

    int i,numBytes = MD5_DIGEST_LENGTH;
    int inputLength = inputString->n;
    unsigned char input[inputLength + 1];
    unsigned char output[numBytes];
    K outputHash = ktn(KG , numBytes);

    for(i=0; i<inputLength; i++)
        {
            input[i] = kC(inputString)[i];
        }

    MD5(input, inputLength, output);

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

    int i,numBytes = SHA256_DIGEST_LENGTH;
    int inputLength = inputString->n;
    unsigned char input[inputLength + 1];
    unsigned char output[numBytes];
    K outputHash = ktn(KG , numBytes);

    for(i=0; i<inputLength; i++)
        {
            input[i] = kC(inputString)[i];
        }

    SHA256(input, inputLength, output);

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

    int i,numBytes = SHA512_DIGEST_LENGTH;
    int inputLength = inputString->n;
    unsigned char input[inputLength + 1];
    unsigned char output[numBytes];
    K outputHash = ktn(KG , numBytes);

    for(i=0; i<inputLength; i++)
        {
            input[i] = kC(inputString)[i];
        }

    SHA512(input, inputLength, output);

    for(i=0; i<numBytes; i++)
        {
            kG(outputHash)[i] = output[i];
        }
    return outputHash;
}




