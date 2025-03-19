#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  

int tree[MAX_SIZE];  
int size = 0; 


void insert(int value) {
    if (size >= MAX_SIZE) {
        printf("Tree is full, cannot insert more elements.\n");
        return;
    }
    tree[size] = value; 
    size++;
}


void deleteNode(int value) {
    for (int i = 0; i < size; i++) {
        if (tree[i] == value) {
            tree[i] = tree[size - 1];  
            size--;  
            printf("Node %d deleted.\n", value);
            return;
        }
    }
    printf("Node %d not found in the tree.\n", value);
}


void preorder(int index) {
    if (index >= size || tree[index] == -1) return;
    printf("%d ", tree[index]);
    preorder(2 * index + 1); 
    preorder(2 * index + 2); 
}


void inorder(int index) {
    if (index >= size || tree[index] == -1) return;
    inorder(2 * index + 1);  
    printf("%d ", tree[index]);
    inorder(2 * index + 2); 
}


void postorder(int index) {
    if (index >= size || tree[index] == -1) return;
    postorder(2 * index + 1); 
    postorder(2 * index + 2);  
    printf("%d ", tree[index]);
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);

    printf("Preorder traversal: ");
    preorder(0);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(0);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(0);
    printf("\n");

    deleteNode(30);

    printf("Preorder traversal after deletion: ");
    preorder(0);
    printf("\n");

    return 0;
}