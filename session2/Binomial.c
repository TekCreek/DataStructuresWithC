#include <stdio.h>
long factorial(int n)
{
    int i,fact=1;
    for(i=n;i>0;i--)
    {
        fact=fact*(i);
    }
    return fact;
}
long binomial_coeff(int n,int r)
{
    return factorial(n)/(factorial(n-r)*factorial(r));
}
int main()
{
    int n,r;
    printf("Enter n value ");
    scanf("%d",&n);
    factorial(n);

    printf("The binomial coeff from nc0 to ncn is :");
    for(r=0;r<=n;r++)
    {
        printf("c(%d,%d)= %ld",n,r,binomial_coeff(n,r));
    }
}