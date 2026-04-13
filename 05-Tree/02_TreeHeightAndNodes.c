#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create(int val) {
    struct node* temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

int height(struct node* root) {
    if (root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return (left > right ? left : right) + 1;
}

int countNodes(struct node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    struct node* root = create(1);
    root->left = create(2);
    root->right = create(3);

    printf("Height: %d\n", height(root));
    printf("Total Nodes: %d", countNodes(root));

    return 0;
}