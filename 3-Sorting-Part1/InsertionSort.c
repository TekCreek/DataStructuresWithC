// Sort logic : Insertion sort 

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

// insertion sort logic
void sort(int b[], int m) {
    int i, j, temp;
    // arrange the i th cell.
    for (i = 1; i < m ; i++) {
        // store current i th cell value in temp.
        temp = b[i];
        // from the previous cell to 0.
        for (j = i-1; j >= 0; j--) {
            if (b[j] > temp) {
                b[j+1] = b[j];
            } else {
                break;
            }
        }

        b[j + 1] = temp;

        printf("\n values in the array after iteration %d \n", i);
        print(b, m);
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

