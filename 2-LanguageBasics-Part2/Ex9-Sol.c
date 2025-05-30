
#include <stdio.h>

void read(int b[], int m) {
    int i;
    printf("Enter %d values into the array ", m);
    for (i = 0; i < m ; i++) {
        scanf("%d", &b[i]);
    }
}

void print(int b[], int m) {
    int i;
    printf("Values into the array are \n");
    for (i = 0; i < m ; i++) {
        printf(" %d ", b[i]);  
    }
}

/* Search for the given element ele in the array and return its index, if not found return -1.*/
int search(int b[],  int n, int ele) {
    int i;
    for (i = 0 ; i < n; i++) {
        if (b[i] == ele) {
            return i;
        }
    }
    return -1;
}

int main() {

    int a[200], n;
    int ele, index;

    printf("Enter n");
    scanf("%d", &n);

    read(a, n);
    print(a, n);

    /* Logic to search for that ele, if -1 print not found other wise print found at <index> */


    printf("Enter value to search: ");
    scanf("%d", &ele);

    index = search(a, n, ele);
    if (index != -1) 
        printf("%d found at index %d ", ele, index);
    else 
        printf("%d not found in the array", ele);

    return 0;
}

