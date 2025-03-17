#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define QUEUE_FULL 1
#define QUEUE_EMPTY 2


struct Queue {
    int limit;
    int arr[10];
    int front, rear;
};


void initialize(struct Queue * p, int maxLimit) {
    p->limit = maxLimit;
    p->front = -1;
    p->rear = -1;
}

/*
    Retruns SUCCESS(0) if enqueue is successful otherwise returns FALIED(1)
*/
int enqueue(struct Queue *p, int value) {

    if (p->rear == p->limit - 1) {
        printf("\nQueue is full");
        return QUEUE_FULL;
    }
    
    p->rear++;
    p->arr[p->rear] = value;

    if (p->front == -1)
        p->front = 0;

    return SUCCESS;
}

/*
    Retruns SUCCESS(0) if enqueue is successful otherwise returns FALIED(1)
*/
int dequeue(struct Queue *p, int *v) {

    if (p->front == -1) {
        printf("\nQueue is empty");
        return QUEUE_EMPTY;
    }
    
    int value = p->arr[p->front];

    // if only one value is present 
    if (p->front == p->rear)
        p->front = p->rear = -1;
    else 
        p->front++;

    *v = value;
    return SUCCESS;
}

int menu() {
    int choice;
    printf("\n 1: Enqueue \n 2: Dequeue \n 3: Exit \n Enter your choice : ");
    scanf("%d", &choice);
    return choice;
}


int main() {
    struct Queue q1;
    
    initialize(&q1, 5);

    int choice;
    int value, status;

    while ( (choice = menu()) != 3) {
        switch(choice) {
            case 1: 
                    printf(" \n Enter value to enqueue :");
                    scanf("%d", &value);
                    status = enqueue(&q1, value);
                    if (status == SUCCESS) {
                        printf("\n Enqueue operation successful \n");
                    } else {
                        printf("\n Enqueue operation failed \n");
                    }
                    break;
            case 2: 
                    status = dequeue(&q1, &value);
                    if (status == SUCCESS) {
                        printf("\n Dequeue operation successful, value removed %d \n", value);
                    } else {
                        printf("\n Dequeue operation failed \n");
                    }
                    break;

        }
    }
    

    return 0;
}


/*
Through dynamic allocation - 

struct Queue {
    int limit;
    int * arr;
    int front, rear;
};

void initialize(struct Queue * p, int maxLimit) {
    p->limit = maxLimit;
    p->arr = (int *)malloc(maxLimit * sizeof(int));
    p->front = -1;
    p->rear = -1;
}

struct Queue q1, q2;
initialize(&q1, 10);
initialize(&q2, 30);


To not to specify struct always you can use typedef.

    typedef int Year; 
    Year a, b; => these are indirectly integers 


without typedef - 

    struct Point {
        int x,y;
    };

    struct Point a, b;

with typedef - 

    typedef struct {
        int x, y;
    } Point;  => new type name is point

    Point a, b;

*/

