/* Pointer */

#include <stdio.h>

struct Employee {
    int id;
    int age;
    char address[100];
    char name[50];
    double salary;
};

int main() {
    long a;
    long b;
    long * p; /* Pointer to integer variable */
    
    struct Employee e;
    struct Employee * q;  /* e : 168, q: 8 (it is a pointer)*/
                         /* any address held in q will belong to a record of type Employee  */

    printf("sizeof a %ld sizeof b %ld sizeof p %ld \n ", sizeof(a), sizeof(b), sizeof(p));

    printf("sizeof e %ld sizeof q %ld \n", sizeof(e), sizeof(q));

    p = &a; 
    *p = 10; 
    p = &b;
    *p = 20;
    printf(" a is %ld b is %ld \n", a, b);
    return 0;
}