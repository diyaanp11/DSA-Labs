#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1)
        printf("Overflow\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Underflow\n");
    else
        printf("Deleted: %d\n", queue[front++]);
}

int main() {
    enqueue(10); enqueue(20);
    dequeue();
}