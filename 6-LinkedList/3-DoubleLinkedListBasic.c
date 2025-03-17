#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node * prev;
    int data;
    struct Node * next;
};


int main() {
    
    int value, choice;
    struct Node * head, *last, *p, *n;

    head = NULL;

    do {
        printf("Enter some value ");
        scanf("%d", &value);

        // create the node 
        n = (struct Node *) malloc( sizeof(struct Node) );

        n->data = value;
        n->next = NULL;

        // if the list is currently empty
        if (head == NULL) {
            head = n;
            head->prev = NULL;
        } else {
            last->next = n;
            n->prev = last;
        }
        last = n;

        printf("continue(y-1, n-0)");
        scanf("%d", &choice);

    } while (choice == 1);


    // print the list 
    printf("\nForward navigation: Values in the list are ...\n");

    p = head;
    while ( p != NULL ) {
        printf(" %d ", p->data);
        p = p->next;
    }

    printf("\nReverse navigation: Values in the list are ...\n");
    
    // move to the last node 
    for(p=head; p->next != NULL; p=p->next)
            ;    

    
    while ( p != NULL ) {
        printf(" %d ", p->data);
        p = p->prev;
    }

    return 0;
}

