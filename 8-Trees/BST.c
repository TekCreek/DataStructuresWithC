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

struct TreeNode * findMin(struct TreeNode * T) {
    if (T == NULL)
        return NULL;

    while (T->left != NULL)
        T = T->left;

    return T;
}

struct TreeNode * delete(struct TreeNode *T, int value) {
    
    if (T == NULL) { // Value is not found
        return NULL;
    }

    // possibly remove from left subtree
    if ( value < T->data ) {
        T->left = delete(T->left , value);
        return T;
    }

    // possibly remove from right subtree
    if (value > T->data) {
        T->right = delete(T->right, value);
        return T;
    }

    // equality case, if condition is optional
    if (T->data == value) {

        // case 1: deleting the leaf node
        if (T->left == NULL && T->right == NULL) {
            free(T); // release the memory allocated for T
            return NULL;
        }

        // case 2: deleting the node with one child
        if (T->left == NULL || T->right == NULL) {
            struct TreeNode * child;
            if (T->left == NULL) {
                child = T->right;
            } else {
                child = T->left;
            }
            free(T);
            return child;
        }    


        // case 3: deleting the node with two children
        // if condition optional
        if (T->left != NULL && T->right != NULL) {
             // find the minimum value from right subtree
             struct TreeNode * minNode = findMin(T->right);   
             // replace the node value with minimum value from right subtree
             int minValue = minNode->data;
             T->data = minValue;
             T->right = delete(T->right, minValue);
             return T;
        }
    }   
}

/*
      10
   7      12
*/

int leafCount(struct TreeNode *T) {
    if (T == NULL)
       return 0;

    // leaf node
    if (T->left == NULL && T->right == NULL)
        return 1;

    return leafCount(T->left) + leafCount(T->right);
}



int menu() {
    int choice;
    printf("\n 1: Insert \n 2: Delete \n 3: Inorder \n 4: Preorder \n 5: Postorder \n 6: LeafCount \n 7: Exit \n Enter your choice : ");
    scanf("%d", &choice);
    return choice;
}


int main() {

    int choice;
    int value, status;
    struct TreeNode * root = NULL;

    while ( (choice = menu()) != 7) {
        switch(choice) {
            case 1: 
                    printf(" \n Enter value to insert :");
                    scanf("%d", &value);
                    root = insert(root, value);
                    break;
            case 2: 
                    printf(" \n Enter value to delete :");
                    scanf("%d", &value);
                    root = delete(root, value);
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
            case 6:
                    value = leafCount(root);
                    printf("\n no of leaf nodes are %d \n", value);
                    break;
        }
    }
}

