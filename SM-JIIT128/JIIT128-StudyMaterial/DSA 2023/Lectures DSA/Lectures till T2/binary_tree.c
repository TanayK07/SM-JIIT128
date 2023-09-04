/*

Program: binary_tree.c
Program to demonstrate Binary Tree




            10
           /  \
           1   2
              / \
              4  5

*/

#include<stdio.h>


struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *root = NULL;

int isEmpty();
struct Node *createNode(int);

void insertTo(struct Node **,int, int , char); // L or R
void printTree(struct Node *);

int isEmpty() {
    return (root==NULL)?1:0;
}

struct Node *createNode(int val) {
    struct Node *temp = NULL;
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// inorder traversal
void printTree(struct Node *node) {
    struct Node *temp = NULL;
    temp = node;
    if(temp != NULL) {
        printTree(temp->left);
        printf("%d ",temp->data);
        printTree(temp->right);
    }
}

void insertTo(struct Node **node, int parentVal, int childVal, char side) {
}

void main() {

    if(root ==  NULL) {
        root = createNode(10);
    }

    root->left = createNode(1);
    root->right = createNode(2);

    root->right->left = createNode(4);
    root->right->right  = createNode(5);

    printTree(root);
}



















