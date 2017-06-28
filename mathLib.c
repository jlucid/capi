#include<stdio.h>
#include"k.h"

K dotProduct(K x,K y)
{

    int i;
    double result = 0.0;

    //Check data types are consistent
    if(x->t != 9 || y->t != 9)
        {
            krr("type");
        }

    //Check vector lengths are equal
    if(x->n != y->n)
        {
            krr("length");
        }

    for(i=0; i<x->n; i++)
        {
            result += kF(x)[i]*kF(y)[i];
        }


    return kf(result);
}
