
#include <stdio.h>

/* Declaration */
int factorial(int);

int main() {
    int n, r, ncr;

    printf("Enter n value ");
    scanf("%d",&n);

    printf("Enter r value ");
    scanf("%d",&r);

    ncr = factorial(n) / (factorial(r) * factorial(n-r));

    printf("ncr value for the given n %d, r %d is %d", n, r, ncr);
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