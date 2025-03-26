
// HeapSort 

#include <stdio.h>

#define leftchild(i) ((2*i)+1)
#define rightchild(i) (leftchild(i)+1)

void buildHeap(int [], int);
void adjust(int [], int, int);
void heapSort(int [], int);

void print(int arr[], int n) {
    int i;
    printf("\n values in the array are ...");
    for (i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int main() {

    int arr[] = {10,2,21,97,84,16,32,71};
               //           k
    int n = 8;

    // buildHeap(arr, n);
    // print(arr, n);

    heapSort(arr, n);
   
    printf("\nSorted values are ....\n");
    print(arr, n);
}


void heapSort(int arr[], int n) {
    int k,temp;


    // build max heap
    buildHeap(arr, n);
    for (k = 1; k < n; k++) {
        // swap arr[0] and arr[n-k]
        temp = arr[0];
        arr[0] = arr[n-k];
        arr[n-k] = temp;

        // adjust the 0th node with reduced size i.e. n-k
        adjust(arr, 0, n-k);
    }
}


void buildHeap(int arr[], int n) {

    int k = n/2; // start k with half of the list so that we leave all the leaf nodes
    for (  ; k >= 0; k--) {
        adjust(arr, k, n);
        
        // ------------- not needed -------
        // printf("\n after adjusting %d th node", k);
        // print(arr, n);
        // ------------- not needed -------
    }

}

// ith node to be adjusted to satisfy the heap property (max).
void adjust(int arr[], int i, int n) {
    
    int temp = arr[i]; // copy the value of ith node to the temp variable.
    int c;                   

    // find any child which is greater than temp and move it to i. 
    c = leftchild(i);
    while (c < n) { // check if left child (index) exists in the array or left child index is with in the array boundary or not.

        // if right child exists and is bigger them move c to the right child.
        if ( c + 1 < n && arr[c+1] > arr[c]) {
            c = c + 1; // point to the right child if it is bigger.
        }

        // if value at child is greater then temp (i.e. the value to be adjusted) then move child value to the 
        // parent i.e. i.
        if ( arr[c] > temp ) {
            arr[i] = arr[c];
            i = c; // position i at c so that you can check its children
            c = leftchild(i);
        } else { // since child value is not greater than temp break the loop
            break;
        }
    }

    // where ever i stops place the temp value at that location.
    arr[i] = temp;
}