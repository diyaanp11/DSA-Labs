#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Create new node
struct node* createNode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

// Merge two sorted lists
struct node* merge(struct node* l1, struct node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->data < l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// Display list
void display(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(5);

    struct node* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);

    struct node* result = merge(l1, l2);

    display(result);

    return 0;
}