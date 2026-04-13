#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct node* temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;

    if (rear == NULL)
        front = rear = temp;
    else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue() {
    if (front == NULL)
        printf("Underflow\n");
    else {
        struct node* temp = front;
        printf("Deleted: %d\n", temp->data);
        front = front->next;
        free(temp);
    }
}

int main() {
    enqueue(10); enqueue(20);
    dequeue();
}