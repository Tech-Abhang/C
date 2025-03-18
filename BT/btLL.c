#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insert(char c[], int n) {
    if (c[n] == '\0') {
        return NULL;
    }
    
    struct Node* tree = createNode(c[n]);
    
    // Insert left child (2*n+1) and right child (2*n+2)
    if (2*n+1 < strlen(c) && c[2*n+1] != '\0') {
        tree->left = insert(c, 2*n+1);
    }
    
    if (2*n+2 < strlen(c) && c[2*n+2] != '\0') {
        tree->right = insert(c, 2*n+2);
    }
    
    return tree;
}

// Function to perform inorder traversal
void inorder(struct Node* tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%c ", tree->data);
        inorder(tree->right);
    }
}

// Function to free the memory allocated for the tree
void freeTree(struct Node* tree) {
    if (tree != NULL) {
        freeTree(tree->left);
        freeTree(tree->right);
        free(tree);
    }
}

int main() {
    char c[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', '\0'};
    
    struct Node* tree = insert(c, 0);
    
    printf("Inorder traversal: ");
    inorder(tree);
    printf("\n");
    
    // Free the allocated memory
    freeTree(tree);
    
    return 0;
}