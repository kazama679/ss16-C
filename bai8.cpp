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

int findPath(Node* root, int value, int path[], int *pathLen) {
    if (root == NULL) {
        return 0; 
    }
    path[*pathLen] = root->data;
    (*pathLen)++;
    if (root->data == value) {
        printf("Duong di tu goc den %d: ", value);
        for (int i = 0; i < *pathLen; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return 1;
    }
    if (findPath(root->left, value, path, pathLen) || findPath(root->right, value, path, pathLen)) {
        return 1;
    }
    (*pathLen)--;
    return 0;
}

int main() {
    Node* tree = NULL;
    int path[100]; 
    int pathLen = 0;
    tree = insertNode(tree, 5);
    tree = insertNode(tree, 3);
    tree = insertNode(tree, 8);
    tree = insertNode(tree, 2);
    tree = insertNode(tree, 4);
    tree = insertNode(tree, 7);
    tree = insertNode(tree, 9);
    int valueToFind = 7;
    if (!findPath(tree, valueToFind, path, &pathLen)) {
        printf("Gia tri %d khong co trong cay.\n", valueToFind);
    }
    valueToFind = 10;
    pathLen = 0; 
    if (!findPath(tree, valueToFind, path, &pathLen)) {
        printf("Gia tri %d khong co trong cay.\n", valueToFind);
    }
    return 0;
}
