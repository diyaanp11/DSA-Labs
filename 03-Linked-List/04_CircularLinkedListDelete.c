#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

// Insert (for setup)
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

// Delete first node
void deleteNode() {
    if (head == NULL) return;

    struct node* temp = head;

    if (head->next == head) {
        head = NULL;
    } else {
        struct node* ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;

        head = head->next;
        ptr->next = head;
    }

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Display
void display() {
    if (head == NULL) return;

    struct node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back)\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    display();
    deleteNode();
    display();

    return 0;
}