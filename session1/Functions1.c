
#include <stdio.h>

/* Declaration */
int factorial(int);

int main() {
    int n, fact;

    printf("Enter n value ");
    scanf("%d",&n);

    fact = factorial(n);

    printf("fACTORIAL = %d",fact);
    return 0;
}


/*Definition */
int factorial(int m) {
    int i, f = 1;
    for (i = m; i > 0; i--) {
        f = f * i;
    }
    return f;
}