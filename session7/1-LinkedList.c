#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};


int main() {
    
    int value, choice;
    struct Node * head, *p, *n;

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
        } else {

            // navigate till the last node
            p = head;
            while (p->next != NULL)
                p = p->next;

            // insert at the end i.e. link the last node next to the new node.
            p->next = n;
            
        }

        printf("continue(y-1, n-0)");
        scanf("%d", &choice);

    } while (choice == 1);


    // print the list 
    printf("\nValues in the list are ...\n");

    p = head;
    while ( p != NULL ) {
        printf(" %d ", p->data);
        p = p->next;
    }


    return 0;
}

