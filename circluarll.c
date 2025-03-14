#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* data;
    struct Node* next;
} 
struct *head = NULL; 

struct Node* createNode(const char* data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = strdup(data);
    newNode->next = NULL;
    return newNode;
};

// Add first
void addFirst(const char* data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head;  // Point to itself in circular list
        return;
    }
    
    // Find the last node
    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    
    newNode->next = head;
    head = newNode;
    last->next = head;  // Last node points to new head
}

// Add last
void addLast(const char* data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head;  // Point to itself in circular list
        return;
    }

    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    last->next = newNode;
    newNode->next = head;  // New last node points to head
}

// Delete first
void startDelete() {
    if (head == NULL) {
        printf("list is empty\n");
        return;
    }

    if (head->next == head) {  // Only one node
        free(head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;  // Update last node to point to new head
    free(temp->data);
    free(temp);
}

// Delete last
void lastDelete() {
    if (head == NULL) {
        printf("list is empty\n");
        return;
    }

    if (head->next == head) {  // Only one node
        free(head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* secondLast = head;
    while (secondLast->next->next != head) {
        secondLast = secondLast->next;
    }

    free(secondLast->next->data);
    free(secondLast->next);
    secondLast->next = head;  // Point to head to maintain circular nature
}

// Print list
void printList() {
    if (head == NULL) {
        printf("list is null\n");
        return;
    }

    struct Node* currNode = head;
    do {
        printf("%s -> ", currNode->data);
        currNode = currNode->next;
    } while (currNode != head);
    printf("(back to head)\n");
}

// Free entire list
void freeList() {
    if (head == NULL) return;

    struct Node* current = head->next;
    struct Node* temp;
    
    while (current != head) {
        temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    free(head->data);
    free(head);
    head = NULL;
}

int main() {
    addFirst("first");
    addLast("second");
    addLast("third");
    printList();
    
    startDelete();
    printf("After deleting first node:\n");
    printList();
    
    lastDelete();
    printf("After deleting last node:\n");
    printList();
    
    // Clean up
    freeList();
    return 0;
}