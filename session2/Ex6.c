
#include <stdio.h>

/*Arrays are always passed by reference */
void change(int b[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        b[i] += 5;
    }
}

int main() {
    int a[] = {10, 20, 30}; /* array identifier always holds the starting address of that array*/
    int i;
    
    change(a, 3);

    for (i = 0; i < 3; i++) {
       printf("\n %d ", a[i]);
    }
    
    return 0;
}

