// Sort logic : Bubble sort 

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

// bubble sort logic
// void sort(int b[], int m) {
//     int i, j, temp;
//     for (i = 1; i < m ; i++) {
//         for (j = 0; j <= (m-i-1); j++) {
//             if (b[j] > b[j+1]) {
//                 temp = b[j];
//                 b[j] = b[j+1];
//                 b[j+1] = temp;
//             }
//         }
//         printf("\n values in the array after iteration %d \n", i);
//         print(b, m);
//     }
// }


void sort(int b[], int m) {
    int i, j, temp;
    int swapped;

    // number of iterations i.e. n - 1
    for (i = 1; i < m ; i++) {

        swapped = 0;
        for (j = 0; j <= (m-i-1); j++) {

            if (b[j] > b[j+1]) {
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
                swapped = 1;
            }

        }

        printf("\n values in the array after iteration %d \n", i);
        print(b, m);

        // none of the elements are swapped in this iteration hence no further iterations are needed.
        if (swapped == 0) {
            printf("None of the elements are swapped hence breaking at iteration %d ", i);
            break;
        }

    }
}

    
int main() {

    int a[200], n;

    printf("Enter n");
    scanf("%d", &n);

    read(a, n);
    sort(a, n);
    print(a, n);

    return 0;
}

