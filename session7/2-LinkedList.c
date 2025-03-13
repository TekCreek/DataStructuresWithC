
#include <stdio.h>
#include <stdlib.h>

enum Menu {ADD=1, INSERT, DELETE, SORT, REVERSE, DISPLAY, EXIT};


struct Node {
    int data;
    struct Node * next;
};

// declarations
struct Node * add ( struct Node *, int );
void display(struct Node *);
struct Node * insert(struct Node *, int, int);
struct Node * delete(struct Node *, int);

void sort();
void reverse();

int menu() {
    int choice;
    printf("\n 1: Add \n 2: Insert \n 3: Delete \n 4: Sort \n 5: *Reverse \n 6: Display \n 7: Exit");
    printf("\n Enter your choice : ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice;
    
    int value, pos;
    struct Node * head = NULL;

    while ( (choice = menu()) != EXIT) {
        switch (choice) {
            case ADD: 
                // printf("\nAdd operation");
                printf("\n Enter value to add : ");
                scanf("%d", &value);

                head = add(head, value);
            
                break;
            case INSERT:
                printf("\n Enter position to insert ");
                scanf("%d", &pos);
                printf("\n Enter value to insert : ");
                scanf("%d", &value);

                head = insert(head, pos, value);

                break;
            case DELETE:
                printf("\n Enter value to delete : ");
                scanf("%d", &value);
                head = delete(head, value);
                break;
            case SORT:
                sort();
                printf("\nSort operation");
                break;
            case REVERSE:
                reverse();
                printf("\nReverse operation");
                break;
            case DISPLAY:
                display(head);
                break;
            case EXIT:
                exit(0);
        }
    }
}

struct Node * allocateNode() {
    struct Node * n = (struct Node *) malloc( sizeof(struct Node) );
    if (n == NULL) {
        printf("Failed to allocate the memory");
        exit(1);
    }
    return n;
}

// definitions

// Adds the value to the end of the list
struct Node * add(struct Node *list, int value) {
    
    struct Node * p;
    
    // New node
    struct Node * n = allocateNode();
    n->data = value;
    n->next = NULL; // You set it to NULL because you know this will always be the last node since it is add operation.


    // if existing list is empty
    if (list == NULL)
        return n; // return the newly created node address so that it will be captured in head refer [ head = add(....) ]

    // move the pointer to the last node in the given list
    for ( p = list; p->next != NULL; p = p->next ) 
         ; // no op

    // link to the new node
    p->next = n;

    return list; // IMP: return the same head point so that head is unchanged refer .... [ head = add(head, value) ]
}

void display(struct Node * list) {
    struct Node * p;

    if (list == NULL) {
        printf("\n List Empty : [list: %p] \n ", list);
        return ;
    }

    printf(" [list: %p ] ->", list);
    p = list;
    while ( p != NULL ) {
        printf("[data: %d, next: %p] -> ", p->data, p->next);
        p = p->next;
    }
    printf("\n");
}

// Pos can be 0 
// if list size = 5 values are present from 0 to 4 and valid positions are 0 to 5, beyond
// that insert will fail.
struct Node * insert(struct Node * list, int pos, int value) {
    struct Node * n, * p;
    int k;

    if (pos < 0) {
        printf(" \nPosition value can not be negative ");
        return list;
    }


    if (list == NULL &&  pos != 0) {
        printf("\n invalid position value ");
        return list;
    }

    // it will change the head
    if (pos == 0) {
        n = allocateNode();
        n->data = value;
        n->next = list;
        return n;   // refer the call   head = insert(head, pos, val)
    }

    // list => {10, 20, 30}  ϕ
    //          p
    // pos => 4
    // value => 25
    
    // k = 4

    p = list;
    k = 1;
    while (k < pos && p != NULL) {
        p = p->next;
        k++;
    }

    if (p != NULL) {
        n = allocateNode();
        n->data = value;
        n->next = p->next;
        p->next = n;
    } else {
        printf("\n Invalid position value \n");
    }
    
    return list;
}


struct Node * delete(struct Node *head, int value) {
    
    struct Node *p, *q;
    
    if (head == NULL) {
        printf("List empty");
        return head;
    } 

    p = head;
    while (p != NULL && p->data != value) {
        q = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("%d value not found in the list", value);
        return head;  // refer ... head = delete(head, value)
    }

    // value found

    // case 1: if this is the first node 
    if (p == head) {
        head = head->next;
        free(p);
    } else { // case 2: middle node
        q->next = p->next;
        free(p);
    }

    return head; // new head in case of (1) or same head in case (2)
}

void sort() {}
void reverse() {}



