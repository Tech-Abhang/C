#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    char* data;
    struct Node* next;
    struct Node* prev;
};

// Global head pointer
struct Node* head = NULL;

// Create new node
struct Node* createNode(const char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = strdup(data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Add at the beginning
void addFirst(const char* data) {
    struct Node* newNode = createNode(data);
    if (head != NULL) {
        head->prev = newNode;
        newNode->next = head;
    }
    head = newNode;
}

// Add at the end
void addLast(const char* data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Add at a specific position
void addMiddle(const char* data, int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    int ctr = 1;
    while (temp != NULL && ctr < pos) {
        temp = temp->next;
        ctr++;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Delete from the beginning
void startDelete() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp->data);
    free(temp);
}

// Delete from the end
void lastDelete() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;

    // If only one node is present
    if (temp->next == NULL) {
        free(temp->data);
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next->data);
    free(temp->next);
    temp->next=NULL;
}

// Delete from a specific position
void middleDelete(int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }
    struct Node* temp = head;
    int ctr = 1;
    while (temp != NULL && ctr < pos) {
        temp = temp->next;
        ctr++;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp->data);
    free(temp);
}

// Print the list
void printList() {
    struct Node* temp = head;
    if (!temp) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%s <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free entire list
void freeList() {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp->data);
        free(temp);
        temp = nextNode;
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

    middleDelete(2);
    printList();

    // startDelete();
    // printList();

    // lastDelete();
    // printList();

    addMiddle("middle", 2);
    printList();

    freeList();
    return 0;
}