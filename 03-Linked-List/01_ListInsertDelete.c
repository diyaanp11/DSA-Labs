#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int val) {
    struct node* temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = head;
    head = temp;
}

void delete() {
    if (head == NULL) return;
    struct node* temp = head;
    head = head->next;
    free(temp);
}

void display() {
    struct node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    insert(10); insert(20);
    display();
    delete();
    display();
}