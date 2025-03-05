// Quick Sort 

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

void quicksort(int arr[], int left, int right) {

    int key, low, high, temp;

    // base condition 
    // either left crossed right or there is only one element
    // hence nothing to do.
    if (left >= right) return;

    key = arr[left];

    // arrangement
    low = left + 1;
    high = right;
    while ( low <= high ) {
        
        // low moves forward
        while (arr[low] <= key && low <= high) 
            low++;


        // high moves backward
        while (arr[high] >= key && low <= high)    
            high--;

        
        // still low and high didn't cross each other
        if (low < high) {
            // swap 
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }

    }

    // move the key to the center i.e. at high
    arr[left] = arr[high];
    arr[high] = key;


    // this completes the arrangement 

    // sort the left half 
    quicksort(arr, left, high - 1);

    // sort the right half
    quicksort(arr, low, right);

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
    quicksort(a, 0, n-1);

    printf("\n sorted array \n ");
    print(a, n);
   
    return 0;
}

