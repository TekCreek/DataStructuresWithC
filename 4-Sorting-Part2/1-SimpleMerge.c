// Simple Merge Sort 

#include <stdio.h>

void read(int arr[], int n) {
    int i;
    printf("\nEnter %d values into the array \n", n);
    for (i = 0; i < n ; i++) {
        scanf("%d", &arr[i]);
    }
}

void print(int b[], int m) {
    int i;
    printf("\nValues into the array are \n");
    for (i = 0; i < m ; i++) {
        printf(" %d ", b[i]);  
    }
}

void simplemerge(int a[], int n, int b[], int m, int c[]) {
    int i = 0, j = 0, k = 0;
    
    // MERGE THE ARRAY VALUES
    while (i < n && j < m) {
        
        if (a[i] < b[j]) 
            c[k++] = a[i++];
        else 
            c[k++] = b[j++];
    }


    // ADD REMAINING ELEMENTS FROM A TO THE TARGET ARRAY
    while (i < n) c[k++] = a[i++];

    // ADD REMAINING ELEMENTS FROM B TO THE TARGET ARRAY
    while (j < m) c[k++] = b[j++];

}


int main() {

    int a[20], n, b[20], m, c[40];
    

    printf("Enter n");
    scanf("%d", &n);
   
    printf("Enter values into the first array (need value in sorted order)");
    read(a, n);


    printf("Enter m");
    scanf("%d", &m);
   
    printf("Enter values into the second array (need value in sorted order)");
    read(b, m);

    simplemerge(a, n, b, m, c);

    printf("\n merged array \n ");
    print(c, n + m);
   
    return 0;
}

