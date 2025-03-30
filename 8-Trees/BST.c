#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    struct TreeNode * left;
    int  data;
    struct TreeNode * right;
};


/*
    main - 
       struct TreeNode * root = NULL;
       menu loop - 
            insert)  value = .... 
                     root = insert(root, value);
*/

struct TreeNode *  insert(struct TreeNode * T, int value) {
    if (T == NULL) {
        // allocating a node
        T = (struct TreeNode *) malloc (sizeof(struct TreeNode));
        if (T == NULL) {
            printf("Unable to allocate memory");
            exit(1);
        }

        // fill the node with the given value 
        T -> data = value;
        // setup left and right subtrees as null since it will always be leaf node
        T -> left = NULL;
        T -> right = NULL;
        return T;
    }

    // automatic else part since if control enters the above if condition, it will return.

    if (value < T->data) { // insert into the left subtree
        T->left = insert( T->left , value);
    } if (value > T->data) {
        T->right = insert( T->right, value);
    }

    return T; // IMP
}

void inorder(struct TreeNode * T) {
    if (T != NULL) {
        inorder(T->left);
        printf("  %d ", T->data);
        inorder(T->right);
    }
}

void preorder(struct TreeNode * T) {
    if (T != NULL) {
        printf("  %d ", T->data);
        preorder(T->left);
        preorder(T->right);
    }
}

void postorder(struct TreeNode * T) {
    if (T != NULL) {
        postorder(T->left);
        postorder(T->right);
        printf("  %d ", T->data);
    }
}


int menu() {
    int choice;
    printf("\n 1: Insert \n 2: Delete \n 3: Inorder \n 4: Preorder \n 5: Postorder \n 6:Exit \n Enter your choice : ");
    scanf("%d", &choice);
    return choice;
}


int main() {

    int choice;
    int value, status;
    struct TreeNode * root = NULL;

    while ( (choice = menu()) != 6) {
        switch(choice) {
            case 1: 
                    printf(" \n Enter value to insert :");
                    scanf("%d", &value);
                    root = insert(root, value);
                    break;
            case 2: 
                    // delete logic
                    break;
            case 3:
                    printf("\n inorder values in the tree are \n");
                    inorder(root);
                    break;
            case 4:
                    printf("\n preorder values in the tree are \n");
                    preorder(root);
                    break;
            case 5:
                    printf("\n postorder values in the tree are \n");
                    postorder(root);
                    break;
        }
    }
}

