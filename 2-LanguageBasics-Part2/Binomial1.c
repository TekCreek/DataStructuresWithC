#include <stdio.h>

long factorial(int n) {
    int i,fact=1;
    for(i=n;i>0;i--) {
        fact=fact*(i);
    }
    return fact;
}

long binomial_coeff(int n,int r) {
    return factorial(n)/(factorial(n-r)*factorial(r));
}

int main() {
    int n,r,a;
    printf("Enter a value ");
    scanf("%d",&a);
    factorial(n);

    printf("The binomial coeff from nc0 to ncn is :");
    for(n = 0; n <= a; n++ ) {
        for(r = 0; r <= n; r++) {
            printf(" %ld", binomial_coeff(n,r));
        }
        printf("\n");
    }

}