#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int val) {
    if ((rear + 1) % MAX == front)
        printf("Overflow\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = val;
    }
}

void dequeue() {
    if (front == -1)
        printf("Underflow\n");
    else {
        printf("Deleted: %d\n", queue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}

int main() {
    enqueue(10); enqueue(20);
    dequeue();
}