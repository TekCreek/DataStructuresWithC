
#include <stdio.h>

int factorial(int m) {
    int i, f = 1;
    for (i = m; i > 0; i--) {
        f = f * i;
    }
    return f;
}

int main() {
    int n, fact;

    printf("Enter n value ");
    scanf("%d",&n);

    fact = factorial(n);

    printf("fACTORIAL = %d",fact);
    return 0;
}