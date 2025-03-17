
#include <stdio.h>

int main() {
    int a[] = {10, 20, 30};
    /* array identifier always holds the starting address of that array*/

    printf("\n%p", a);
    
    printf("\n%d", a[0]);
    printf("\n%d", *a);
    printf("\n%d", *(a+0));

    printf("\n%d", a[1]);
    printf("\n%d", *(a+1));

    printf("\n%d", a[2]);
    printf("\n%d", *(a+2));



    return 0;
}

