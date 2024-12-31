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

int countNodesGreaterThanX(Node* node, int X) {
    if (node == NULL) {
        return 0;
    }
    int count = 0;
    if (node->data > X) {
        count = 1;
    }
    return count + countNodesGreaterThanX(node->left, X) + countNodesGreaterThanX(node->right, X);
}

void inOrdered(Node* node) {
    if (node != NULL) {
        inOrdered(node->left);
        printf("%d ", node->data);
        inOrdered(node->right);
    }
}

int main() {
    Node* tree = NULL;
    int n, value, X;

    printf("Nhap so luong gia tri muon them vao cay: ");
    scanf("%d", &n);

    printf("Nhap cac gia tri de chen vao cay:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        tree = insertNode(tree, value);
    }

    printf("Cay theo thu tu trung vi: ");
    inOrdered(tree);
    printf("\n");

    printf("Nhap gia tri X: ");
    scanf("%d", &X);

    int count = countNodesGreaterThanX(tree, X);
    printf("So luong nut co gia tri lon hon %d: %d\n", X, count);

    return 0;
}
