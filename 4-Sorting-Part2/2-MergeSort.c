// Simple Merge Sort 

#include <stdio.h>

void read(int arr[], int n) {
    int i;
    printf("\nEnter %d values into the array \n", n);
    for (i = 0; i < n ; i++) {
        scanf("%d", &arr[i]);
    }
}

void print(int arr[], int n) {
    int i;
    printf("\nValues into the array are \n");
    for (i = 0; i < n ; i++) {
        printf(" %d ", arr[i]);  
    }
}

// declaration line
void simplemerge(int arr[], int, int, int);

void mergesort(int arr[], int l, int r) {
    int m;

    // IMP: base condition which stops recursion.
    if (l >= r) return;

    m = (l + r) / 2;

    // sort the left half
    mergesort( arr, l , m);

    // sort the right half
    mergesort( arr, m+1 , r);

    // merge both the halves 
    simplemerge( arr, l, m, r);
}

void simplemerge(int arr[], int l, int m, int r) {
    int i = l;   // IMP NOTE i should start at l the first position of the array segment
    int j = m+1; // IMP NOTE m+1 is the left of second array
    int k = 0;
    
    int c[20];

    // MERGE THE ARRAY VALUES
    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) 
            c[k++] = arr[i++];
        else 
            c[k++] = arr[j++];
    }


    // ADD REMAINING ELEMENTS FROM A TO THE TARGET ARRAY
    while (i <= m) c[k++] = arr[i++];

    // ADD REMAINING ELEMENTS FROM B TO THE TARGET ARRAY
    while (j <= r) c[k++] = arr[j++];

    // copy the array values from c to arr (l to r)
    k = 0; // IMP 
    for (i = l ; i <= r; i++) {
        arr[i] = c[k];
        k++;
    }
}


int main() {
    int a[20], n;

    printf("Enter n");
    scanf("%d", &n);
   
    printf("Enter values into the array");
    read(a, n);

    printf("\n values in the array \n ");
    print(a, n);

    // first call hence left is 0 and right is n-1
    mergesort(a, 0, n-1);

    printf("\n sorted array \n ");
    print(a, n);
   
    return 0;
}

