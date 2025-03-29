
#include <stdio.h>

#define MAX 100
#define SUCCESS 0
#define QUEUE_EMPTY 1

typedef struct {
    int arr[MAX];
    int n;
} PriorityQueue ;

#define parentIndex(i) ((i-1)/2)
#define leftchild(i) ((2*i)+1)


int enqueue(PriorityQueue *q, int value) {
    int p = q->n;
    int parent;

    while (p > 0) { // stop if p = 0 
       parent = parentIndex(p);
       // Assuming this is maxHeap, parent should always be greater than the child value.
       // if the to be inserted value is greater than parent then move parent to the child location.
       if (q->arr[parent] < value) {
         q->arr[p] = q->arr[parent];
         p = parent; // move p to the parent location so that you can check subsequent parent node values.
       } else {
           break;  // break if parent is greater than value.
       }
    }

    // save the value at location where p stops. 
    q->arr[p] = value;
    q->n++; // IMP as new element is added to the array increment the size.

    return SUCCESS;
}

// ith node to be adjusted to satisfy the heap property (max).
void adjust(PriorityQueue *q, int i) {
    
    int temp = q->arr[i]; // copy the value of ith node to the temp variable.
    int c;  

    int n = q->n; // copy q->n to local variable n so that we can directly refer to n 
    int *arr = q->arr; // copy the q->arr pointer to local pointer arr for easy reference.                 

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

int dequeue(PriorityQueue *q, int *value) {
    
    if (q->n == 0) { // queue is empty
        return QUEUE_EMPTY;
    }

    // valueToBeDeleted is passed through value pointer.
    *value = q->arr[0];

    q->arr[0] = q->arr[(q->n - 1)]; // copy the last cell (n-1) value to the 0th cell.
    q->n--; // reduce the size by 1.

    // adjustment is not required if n is either 0 or 1.
    if (q->n > 1) {
        // adjust the 0th cell.
        adjust(q, 0);
    }

    return SUCCESS;
}

void printQueue(PriorityQueue *q) {
    int i;
    printf("\n Values in the queue are .... \n");
    for ( i = 0; i < q->n ; i++) {
        printf("  %d  ", q->arr[i]);
    }
    printf("\n");
}

int menu() {
    int choice;
    printf("\n 1: Enqueue \n 2: Dequeue \n 3: Print \n 4: Exit \n Enter your choice : ");
    scanf("%d", &choice);
    return choice;
}


int main() {

    PriorityQueue queueRec;
    queueRec.n = 0; // IMP

    int choice;
    int value, status;

    while ( (choice = menu()) != 4) {
        switch(choice) {
            case 1: 
                    printf(" \n Enter value to enqueue :");
                    scanf("%d", &value);
                    status = enqueue(&queueRec, value);
                    if (status == SUCCESS) {
                        printf("\n Enqueue operation successful \n");
                    } else {
                        printf("\n Enqueue operation failed \n");
                    }
                    break;
            case 2: 
                    status = dequeue(&queueRec, &value);
                    if (status == SUCCESS) {
                        printf("\n Dequeue operation successful, value removed %d \n", value);
                    } else {
                        printf("\n Dequeue operation failed \n");
                    }
                    break;
            case 3:
                    printQueue( &queueRec );
                    break;
        }
    }
}





