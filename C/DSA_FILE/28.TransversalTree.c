#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int value) {
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void INORDER(struct node* root) {
    if(root != NULL) {
        INORDER(root->left);
        printf("%d ", root->data);
        INORDER(root->right);
    }
}

void PREORDER(struct node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        PREORDER(root->left);
        PREORDER(root->right);
    }
}

void POSTORDER(struct node* root) {
    if(root != NULL) {
        POSTORDER(root->left);
        POSTORDER(root->right);
        printf("%d ", root->data);
    }
}

int main() {

    struct node* root;

    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder Traversal:\n");
    INORDER(root);

    printf("\n\nPreorder Traversal:\n");
    PREORDER(root);

    printf("\n\nPostorder Traversal:\n");
    POSTORDER(root);

    return 0;
}