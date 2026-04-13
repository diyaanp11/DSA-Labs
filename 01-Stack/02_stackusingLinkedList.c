#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int val) {
    struct node* temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = top;
    top = temp;
}

void pop() {
    if (top == NULL)
        printf("Underflow\n");
    else {
        struct node* temp = top;
        printf("Popped: %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void display() {
    struct node* temp = top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    push(10); push(20);
    display();
    pop();
}