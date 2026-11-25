
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// In-order: Left, Root, Right
void inOrder(struct Node* root) {
    if (root == NULL) return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Pre-order: Root, Left, Right
void preOrder(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Post-order: Left, Right, Root
void postOrder(struct Node* root) {
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main() {

    struct Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("In-order: ");
    inOrder(root);

    printf("\nPre-order: ");
    preOrder(root);

    printf("\nPost-order: ");
    postOrder(root);

    return 0;
}
