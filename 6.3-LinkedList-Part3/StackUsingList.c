#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

int menu() {
    int choice;
    printf("\n 1: Push \n 2: Pop \n 3: Exit \n Enter your choice : ");
    scanf("%d", &choice);
    return choice;
}

struct Node * allocateNode() {
    struct Node * n;
    n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Unable to allocate node");
        exit(1);
    }
    return n;
}


int main() {
    struct Node * head = NULL;
    struct Node * n, * p;
    int choice;
    int value;
    while ( (choice = menu()) != 3 ) {
        switch( choice ) {
            case 1: // push: add the new node to the front of the list.
                    printf("Enter value to push ");
                    scanf("%d", &value);   
                    n = allocateNode();
                    n->data = value;
                    n->next = head;
                    head = n;
                    break;
            case 2: // pop : delete the first node from the list.
                    if (head == NULL) {
                        printf("\n Stack empty");
                    } else {
                        printf("\n Popped value %d ", head->data);
                        p = head; // save the current head value so that we can free memory
                        head = head->next; // point to the second node 
                        free(p);
                    }
                    break;
        }
    }

}