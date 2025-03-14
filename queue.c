#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

// Dequeue operation
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front++]);
}

// Display queue
void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    displayQueue();
    dequeue();
    displayQueue();
    return 0;
}