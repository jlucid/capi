/* Fine name: refcount.c */
#include "common.h"

int main() {
  K a, b;
  khp("", -1); // initialise memory if not opening connection before allocation
  a= ki(3);    // Create K object a
  printf("New K object a has ref count = %d\n", a->r);

  b= a;  // Set b equal to a
  r1(a); // Increment a's reference count
  printf("incremented ref count of a = %d\n", a->r);
  printf("ref count of b = %d\n", b->r);

  r0(b); // Decrement b's reference count
  printf("decrement ref count of b = %d\n", b->r);
  printf("ref count of a was decremented to = %d\n", a->r);

  printf("value of a is still available: %d\n", a->i);

  r0(a); // When an object of ref count 0 passed to r0, the object is destroyed
  return EXIT_SUCCESS;
}
