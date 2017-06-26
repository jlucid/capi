#include<stdio.h>
#include"k.h"

int main()
{
    int i;
    I handle;
    I portnumber = 12345;
    S hostname   = "localhost";
    S usernamePassword = "kdb:pass";
    K x,keys,values;

    handle = khpu(hostname,portnumber,usernamePassword);

    x = k(handle,"`a`b`c!((1;2;3);(10.0;20.0);(`AB`CD`EF`GH))",(K)0);
    printf("Dict type = %d\n",x->t);
    printf("Num elements = %lld (keys and values)\n",x->n);

    keys   = kK(x)[0];
    values = kK(x)[1];

    printf("Keys type = %d\n",keys->t);
    printf("Num keys = %lld\n",keys->n);

    printf("Values type = %d\n",values->t);
    printf("Num values = %lld\n",values->n);

    for(i=0; i<keys->n; i++)
        {
            printf("keys[%d] = %s\n",i,kS(keys)[i]);
        }

    for(i=0; i<values->n; i++)
        {
            printf("values[%d] has length %lld\n",i,kK(values)[i]->n);
        }

    printf("values[0;] = %lld %lld %lld\n", kJ(kK(values)[0])[0],kJ(kK(values)[0])[1],kJ(kK(values)[0])[2]);
    printf("values[1;] = %lf %lf\n",kF(kK(values)[1])[0],kF(kK(values)[1])[1]);
    printf("values[2;] = %s %s %s %s\n", kS(kK(values)[2])[0],kS(kK(values)[2])[1],kS(kK(values)[2])[2],kS(kK(values)[2])[3]);

    kclose(handle);
    return 0;
}
