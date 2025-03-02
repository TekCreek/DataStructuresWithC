
#include <stdio.h>

void read(int b[], int m) {
    int i;
    printf("Enter %d values into the array ", m);
    for (i = 0; i < m ; i++) {
        scanf("%d", &b[i]);
                                    /* scanf("%d", b+i)); */
                                    /* scanf("%d", &(*(b+i))); */
    }
}

void print(int b[], int m) {
    int i;
    printf("Values into the array are \n");
    for (i = 0; i < m ; i++) {
        printf(" %d ", b[i]);  /* printf("%d", *(b+i) ); */
    }
}

int main() {

    int a[200], n;

    printf("Enter n");
    scanf("%d", &n);

    read(a, n);
    print(a, n);

    return 0;
}

