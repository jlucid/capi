#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "k.h"

I handleOk(I handle){
  if(handle>0) return 1;
  if(handle==0)
    fprintf(stderr,"Authentication error %d\n", handle);
  else if(handle==-1)
    fprintf(stderr,"Connection error %d\n",handle);
  else if(handle==-2)
    fprintf(stderr,"Time out error %d\n",handle);
  return 0;
}
// check result of remote call
// it can be either 0(network error) or K object
// if type of the object is -128(error) print error and release object.
// K objects with type -128 exist only when calling from standalone C API and not valid for shared objects
I isRemoteErr(K x) {
  if(!x){
    fprintf(stderr,"Network error: %s\n",strerror(errno));
    return 1;
  }else if(-128 == xt) {
    fprintf(stderr,"Error message returned : %s\n",x->s);
    r0(x);
    return 1;
  }
  return 0;
}

