
#include <stdio.h>
#include <stdlib.h>

enum Menu {ADD=1, INSERT, DELETE, DISPLAY, EXIT};


struct Node {
    struct Node * prev;
    int data;
    struct Node * next;
};

// declarations
struct Node * add ( struct Node *, int );
void display(struct Node *);
struct Node * insert(struct Node *, int, int);
struct Node * delete(struct Node *, int);


int menu() {
    int choice;
    printf("\n 1: Add \n 2: Insert \n 3: Delete \n 4: Display \n 5: Exit");
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
struct Node * add(struct Node *head, int value) {
    
    struct Node * p;
    
    // New node
    struct Node * n = allocateNode();
    n->data = value;

    // this will always be last node since the operation is add(add to the end of the list)
    // if list is empty
    if (head == NULL) {
        head = n;
        // because n is the only node its prev and next will point to same node itself.
        n->next = head;
        n->prev = head;
    } else { // list is not empty

        // move the pointer to the end of the list
        // Node is last node when the next pointer is pointing to head i.e. the first node.
        // THIS LOOP IS NORMALLY REQUIRED IN CIRCULAR SINGLE LINKED LIST
        for (p = head; p->next != head; p = p->next ) 
           ; // no op

        /* IMPORTANT : IN CASE OF CIRCULAR DOUBLE LINKED LIST ABOVE FOR LOOP CAN BE COMPLETELY REPLACED WITH 
           p = head->prev; // SINCE FIRST NODE PREV WILL POINT TO LAST NODE
        */
        
        // RULE1: FILL THE EMPTY CELLS FIRST
        n->prev = p;
        n->next = p->next;

        // RULE2: NOW CHANGE THE OTHER NODE LINKS
        p->next->prev = n;
        p->next = n;

    }

    return head;
}

void display(struct Node * head) {
    struct Node * p;

    if (head == NULL) {
        printf("\n [head: %p] ", head);
        return ;
    }
    
    printf("\n [head: %p]", head);
    p = head;
    do {
        printf(" -> (addr: %p,  prev: %p, data: %d, next: %p) ",p, p->prev, p->data, p->next);
        p = p->next;
    } while ( p != head );

    printf("\n");
}

// Pos can be 0 
// if list size = 5 values are present from 0 to 4 and valid positions are 0 to 5, beyond
// that insert will fail.
struct Node * insert(struct Node * head, int pos, int value) {
    struct Node * n, * p;
    int k;

    if (pos < 0) {
        printf(" \nPosition value can not be negative ");
        return head;
    }


    if (head == NULL &&  pos != 0) {
        printf("\n invalid position value ");
        return head;
    }

    // insert in front of the list at 0.
    if (pos == 0) {
        n = allocateNode();
        n->data = value;

        if (head == NULL) { // if list is empty
            head = n;
            n->prev = head;
            n->next = head;
        } else {
                     // last node 
            n->prev = head->prev;
            n->next = head;

            // lastnode->next 
            head->prev->next = n;
            head->prev = n;

            head = n;
        }

        return head;
    }

    // it is not zero

    // head: 1000

    // [ 1000 => (prev: 2000, data: 10, next: 2000) , 2000 => (prev: 1000 , data: 20 , next: 1000)
    //    p                                             

    // insert 25 at 3

    // k: 2
    // pos: 1

    p = head;
    k = 1; // 2 < 3
    while (k < pos) {
        p = p->next;

        if (p == head) // rotation is finished
          break;

        k++;
    }

    if (k < pos) {
        printf("\n Invalid position %d \n", pos);
        return head; // no change
    }
    
    n = allocateNode();
    n->data = value;
    
    n->prev = p;
    n->next = p->next;

    p->next->prev = n;
    p->next = n;
    
    return head;
}


struct Node * delete(struct Node *head, int value) {
    
    struct Node *p;
    int found;
    if (head == NULL) {
        printf("List empty");
        return head;
    } 

    p = head;
    found = 0;
    do {
        if (p->data == value) {
            found = 1;
            break;
        }
        p = p->next;
    } while (p != head);


    if (found == 0) {
        printf("%d value not found in the list", value);
        return head;  // refer ... head = delete(head, value)
    }
    
    // value found

    // case 1: if this is the first node 
    if (p == head) {
        // case 1.a: single node case 
        if (p->prev == p->next) {
            head = NULL;
            free(p);
        } else { // case 1.b: multi node 
            p->prev->next = p->next;
            p->next->prev = p->prev;
            head = p->next; // point head to the second node
            free(p);      
        }
        
    } else { // case 2: middle node
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }

    return head; 
}
