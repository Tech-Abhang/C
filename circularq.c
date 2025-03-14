#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5 

int queue[N];
int front = -1;
int rear = -1;

//insert
int enqueue(int x){
    if((rear == ((front - 1) % N))){
        printf("Queue is full\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else if(rear == N-1 && front != 0){
        rear = 0;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear] = x;
    }
}

//delete 
int dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        front = rear = -1 ; 
    }
    else if(rear == N-1){
        front = 0 ;
    }
    else{
        front ++ ;
    }
}

//display
void display(){
    if(front<rear){
        for(int i=front ; i<rear ; i++){
            printf("%d\n",queue[i]);
        }
    }else{
        for(int i = front ; i<N ; i++){
            printf("%d\n",queue[i]);
        }
        for(int i=0 ; i<rear ; i++){
            printf("%d\n",queue[i]);
        }
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
    return 0;
}