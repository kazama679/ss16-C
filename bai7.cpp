#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else {
        node->right = insertNode(node->right, data);
    }
    return node;
}

int isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }
    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

void inOrdered(Node* node) {
    if (node != NULL) {
        inOrdered(node->left);
        printf("%d ", node->data);
        inOrdered(node->right);
    }
}

int main() {
    Node* tree1 = NULL;
    tree1 = insertNode(tree1, 5);
    tree1 = insertNode(tree1, 3);
    tree1 = insertNode(tree1, 8);
    tree1 = insertNode(tree1, 2);
    tree1 = insertNode(tree1, 4);
    Node* tree2 = NULL;
    tree2 = insertNode(tree2, 5);
    tree2 = insertNode(tree2, 3);
    tree2 = insertNode(tree2, 8);
    tree2 = insertNode(tree2, 2);
    tree2 = insertNode(tree2, 4);
    Node* tree3 = NULL;
    tree3 = insertNode(tree3, 5);
    tree3 = insertNode(tree3, 3);
    tree3 = insertNode(tree3, 8);
    tree3 = insertNode(tree3, 2);
    tree3 = insertNode(tree3, 6);
    printf("Cay 1: ");
    inOrdered(tree1);
    printf("\n");
    printf("Cay 2: ");
    inOrdered(tree2);
    printf("\n");
    printf("Cay 3: ");
    inOrdered(tree3);
    printf("\n");
    if (isIdentical(tree1, tree2)) {
        printf("Cay 1 va Cay 2 giong nhau.\n");
    } else {
        printf("Cay 1 va Cay 2 khac nhau.\n");
    }
    if (isIdentical(tree1, tree3)) {
        printf("Cay 1 va Cay 3 giong nhau.\n");
    } else {
        printf("Cay 1 va Cay 3 khac nhau.\n");
    }
    return 0;
}
