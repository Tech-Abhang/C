#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    char* data;
    struct Node* next;
};

// Global head pointer
struct Node* head ;

// Create new node
struct Node* createNode(const char* data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = strdup(data);
    newNode->next = NULL;
    return newNode;
}

// Add first
void addFirst(const char* data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

// Add last
void addLast(const char* data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* currNode = head;
    while (currNode->next != NULL) {
        currNode = currNode->next;
    }
    currNode->next = newNode;
}

//add in the middle
void addMiddle(const char* data, int pos){
    struct Node* newNode = createNode(data);
    struct Node* lastNode = head;
    struct Node* secLastNode = head;

    int ctr = 1 ;
    if(pos>0){
        while(ctr<pos){
            secLastNode = lastNode;
            lastNode = lastNode->next;
            ctr++;
        }
        secLastNode->next = newNode;
        newNode->next = lastNode;
    }
    else{
        printf("invalid position\n");
    }
}

// Delete first node
void startDelete() {
    if (head == NULL) {
        printf("list is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp->data);
    free(temp);
}

// Delete last node
void lastDelete() {
    if (head == NULL) {
        printf("list is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* secondLastNode = head;
    struct Node* lastNode = head->next;

    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
        secondLastNode = secondLastNode->next;
    }

    free(lastNode->data);
    free(lastNode);
    secondLastNode->next = NULL;
}

//delete in the middle
void middleDelete(int pos){
    struct Node* temp = head;
    struct Node* sectemp = head;

    int ctr = 1;
    if(pos>0){
        while(ctr<pos){
            sectemp = temp;
            temp = temp->next;
            ctr++;
        }
        sectemp->next = temp->next;
        free(temp->data);
        free(temp);
    }
    else{
        printf("invalid position\n");
    }
}
// Print list
void printList() {
    if (head == NULL) {
        printf("list is null\n");
        return;
    }

    struct Node* currNode = head;
    while (currNode != NULL) {
        printf("%s -> ", currNode->data);
        currNode = currNode->next;
    }
    printf("NULL\n");
}

// Free entire list
void freeList() {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    head = NULL;
}

int main() {
    addFirst("1");
    addLast("2");
    addLast("name");
    addLast("is");
    addLast("abhang");
    printList();
    addMiddle("middle",2);
    printList();
    middleDelete(2);
    printList();
    // startDelete();
    // printList();
    // lastDelete();
    // printList();
    // middleDelete(1);
    // printList();
    
    // Clean up
    freeList();
    return 0;
}
