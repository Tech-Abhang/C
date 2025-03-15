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
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Add at the beginning
void addFirst(const char* data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head->prev = head;
    } else {
        struct Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;
        head = newNode; // Update head to new node
    }
}

// Add at the end
void addLast(const char* data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head->prev = head;
    } else {
        struct Node* temp = head->prev;  // Directly access the last node using head->prev
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }
}

// Add at a specific position
void addMiddle(const char* data, int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        addFirst(data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    int ctr = 1;

    // Traverse to position
    while (ctr < pos - 1 && temp->next != head) {
        temp = temp->next;
        ctr++;
    }

    if (ctr < pos - 1) {
        printf("Position out of bounds\n");
        free(newNode->data);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete from the beginning
void startDelete() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head->data);
        free(head);
        head = NULL;
    } else {
        struct Node* last = head->prev;
        struct Node* temp = head;
        head = head->next;
        head->prev = last;
        last->next = head;

        free(temp->data);
        free(temp);
    }
}

// Delete from the end using only one variable
void lastDelete() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) { 
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head->prev; // Directly access the last node
        temp->prev->next = head;       // Second-last node points to head
        head->prev = temp->prev;       // Head points back to second-last node
        free(temp);
    }
}

// Delete from a specific position
void middleDelete(int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        startDelete();
        return;
    }

    struct Node* temp = head;
    int ctr = 1;

    // Traverse to the position
    while (ctr < pos && temp->next != head) {
        temp = temp->next;
        ctr++;
    }

    if (ctr < pos) {
        printf("Position out of bounds\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp->data);
    free(temp);
}

// Print the list
void printList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%s <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Free entire list
void freeList() {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        struct Node* nextNode = temp->next;
        free(temp->data);
        free(temp);
        temp = nextNode;
    } while (temp != head);

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

    addMiddle("middle", 2);
    printList();

    startDelete();
    printList();

    lastDelete();
    printList();

    freeList();
    return 0;
}