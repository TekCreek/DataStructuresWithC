
#include <stdio.h>
int main() {
    int n,i,fact=1;
    printf("Enter n value ");
    scanf("%d",&n);
    for(i=n;i>0;i--)
    {
        fact=fact*i;

    }
    printf("fACTORIAL =%d",fact);
    return 0;
}