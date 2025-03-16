#include <stdio.h>
#include <stdlib.h>

struct Node {
    char* data ; 
    struct Node* left ; 
    struct Node* right ;
}

void main(){
    struct Node* tree = NULL ; 
    char* c[] = {"A","B","C","D","E","F","0","G","0","0","0","0","0","0","0"} ;
    tree = insert(c,0)
    inorder(tree) ;
    return 0;
}

struct Node* insert(char c[] , int i){
    struct Node* tree = NULL;
    
    if(c[n] != NULL){
        tree = Node* malloc(sizeOf(Node));
        tree->left = insert(c,2*i+1);
        tree->data = c[i];
        tree->right = insert(c,2*i+2);
    }
    return tree ;
}

void inorder(struct Node* tree){
    if(tree!=NULL){
        inorder(tree->left);
        printf("%s",tree->data);
        inorder(tree->right);
    }
}