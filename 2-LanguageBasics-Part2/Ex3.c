/* Pointer */

#include <stdio.h>

int main() {
    long a;
    long * p; /* Pointer to long integer variable */
    long * * q; /* q is a pointer to a pointer to long integer variable */
    
    p = &a;
    q = &p; 

    a = 10;
    a = a + *p + **q;

    printf(" a is %ld \n", a);
    return 0;
}