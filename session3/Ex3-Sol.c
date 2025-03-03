#include <stdio.h>

void read(int b[], int m) {
    int i;
    printf("\nEnter %d values into the array \n", m);
    for (i = 0; i < m ; i++) {
        scanf("%d", &b[i]);
    }
}

void print(int b[], int m) {
    int i;
    printf("\nValues into the array are \n");
    for (i = 0; i < m ; i++) {
        printf(" %d ", b[i]);  
    }
}

// Selection Sort 
/* 
    for i = 0 to n - 2
        identify the next smallest from the (i+1) to n-1 
        swap the ith cell value with the smallest cell value
*/
void sort(int b[], int m) {
    int i, j, pos, min, temp;

    for (i = 0; i < (m-1); i++) {

        min = b[i];
        pos = i;

        for (j = i + 1; j < m; j++) {
            if (b[j] < min) {
                min = b[j];
                pos = j;
            }
        }

        // swap ith cell and pos cell.
        if (pos != i) {
            b[pos] = b[i];
            b[i] = min; 
        }


        printf("\n values in the array after iteration %d \n", i);
        print(b, m);
    }
}


// Apply binary search, return index at which the element is found otherwise -1.
// Prerequisite - given array should be in sorted order.
int search (int a[], int n, int ele) {

    int  l, r, mid;
    
    l = 0;
    r = n - 1;

    while ( l <= r ) {
        mid = (l + r) / 2;
        if (ele < a[mid]) {
            r = mid - 1;
        } else if (ele > a[mid]) {
            l = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}


int main() {

    int a[200], n, ele;
    int index;

    printf("Enter n");
    scanf("%d", &n);

    read(a, n);
    sort(a, n);
    print(a, n);


    printf("Enter element to search \n");
    scanf("%d", &ele);

    index = search(a, n, ele);
    if ( index != -1) {
        printf("%d found at index %d ", ele, index);
    } else {
        printf("%d not found in the array", ele);
    }

    return 0;
}

