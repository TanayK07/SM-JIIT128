/*

Program: binary_search_tree.c
Program for demonstration of Binary Search Tree




Tree -> Binary Tree -> with condition (Binary Search Tree)

                for every node - left nodes should be less than parent
                                  right nodes should be greater than parent.

*/

#include<stdio.h>

struct Node  {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

int isEmpty();

// insertion
void insert(struct Node **, int);
void insertNode(int);
struct Node *createNode(int);


// tree traversals
void inorder(struct Node *); // L - P - R
void preorder(struct Node *); // P - L - R
void postorder(struct Node *); // L - R - P

// other operations
int findMin(struct Node *);
int findMax(struct Node *);

// removal of nodes
void removeNode(int);
void remove_node(struct Node **,int);


// search operation - binary search
void searchNode(int);
void search(struct Node *, int);

struct Node *createNode(int val) {
    struct Node *temp = NULL;
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insertNode(int val) {
    insert(&root,val);
}

void insert(struct Node **node, int val) {
    struct Node *temp = NULL;
    temp = *node;
    if(*node == NULL) {
        *node = createNode(val);
    } else if (val < temp->data) {
        insert(&temp->left, val);
    } else if (val > temp->data) {
        insert(&temp->right, val);
    } else ; // duplicate element
}

void inorder(struct Node *node) {
    struct Node *temp = NULL;
    temp = node;
    if(temp != NULL) {
        inorder(temp->left);
        printf("%d  ",temp->data);
        inorder(temp->right);
    }
}

void preorder(struct Node *node) {
    struct Node *temp = NULL;
    temp = node;
    if(temp != NULL) {
        printf("%d  ",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct Node *node) {
    struct Node *temp = NULL;
    temp = node;
    if(temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d  ",temp->data);
    }
}

int findMin(struct Node *node) {
    struct Node *temp = NULL;
    temp = node;
    if(temp == NULL) return -999;
    if(temp->left == NULL) return temp->data;
    else return findMin(temp->left);
}

int findMax(struct Node *node) {
    struct Node *temp = NULL;
    temp = node;
    if(temp == NULL) return -999;
    if(temp->right == NULL) return temp->data;
    else return findMax(temp->right);
}

void removeNode(int val) {
    remove_node(&root, val);
}

/*

    1. Removing leaf node
    2. Removing node with one child
    3. Removing node with two childs

*/

void remove_node(struct Node **node, int val) {
    struct Node *temp = NULL;
    temp = *node;
    if(temp == NULL) return;
    else if(val < temp->data) remove_node(&temp->left, val);
    else if(val > temp->data) remove_node(&temp->right, val);
    else if(val == temp->data) {
        // Node with no child
        if(temp->left == NULL && temp->right == NULL) {
            *node = NULL;
            return;
        }
        // Node with two childs
        else if(temp->left!=NULL && temp->right != NULL) {
            temp->data = findMin(temp->right);
            remove_node(&temp->right, temp->data);
        } else {
            // Node with left or right child
            struct Node *tt = NULL;
            tt = *node;
            *node = (*node)->left?(*node)->left:(*node)->right;
            free(tt);
            printf("The node %d is removed ...\n",val);
        }
    }
}



// Binary search
void searchNode(int val) {
    search(root,val);
}

void search(struct Node *node, int val) {
    struct Node *temp = NULL;
    temp = node;

    if(temp == NULL) return;
    else if(val < temp->data) search(temp->left, val);
    else if(val > temp->data) search(temp->right, val);
    else if(val == temp->data) {
        printf("The element %d found ..... \n", val);
        return;
    } else ;
}


void main() {

    insertNode(6);
    insertNode(2);
    insertNode(1);
    insertNode(8);
    insertNode(5);
    insertNode(3);
    insertNode(4);

    printf("\n");
    inorder(root); // Elements will be printed in ascending order

    printf("\n");
    preorder(root);


    printf("\n");
    postorder(root);

    printf("\nMinimum element in BST : %d \n",findMin(root));

    printf("\nMaximum element in BST : %d \n",findMax(root));

    removeNode(3);

    printf("\n");
    inorder(root);

    searchNode(4);

   

    printf("\n");
    inorder(root);

}























