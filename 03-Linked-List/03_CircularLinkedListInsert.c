#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

// Insert at end in circular list
void insert(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;

    if (head == NULL) {
        head = temp;
        temp->next = head;
    } else {
        struct node* ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;

        ptr->next = temp;
        temp->next = head;
    }
}

// Display circular list
void display() {
    if (head == NULL) return;

    struct node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    display();

    return 0;
}