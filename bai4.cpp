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
        node = createNode(data);
    }
    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }
    return node;
}

void preOrdered(Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preOrdered(node->left);
        preOrdered(node->right);
    }
}

void inOrdered(Node* node) {
    if (node != NULL) {
        inOrdered(node->left);
        printf("%d ", node->data);
        inOrdered(node->right);
    }
}

void postOrdered(Node* node) {
    if (node != NULL) {
        postOrdered(node->left);
        postOrdered(node->right);
        printf("%d ", node->data);
    }
}

int treeHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(node->left);
    int rightHeight = treeHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countLeaves(Node* node) {
    if (node == NULL) {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    return countLeaves(node->left) + countLeaves(node->right);
}

Node* searchNode(Node* node, int target) {
    if (node == NULL || node->data == target) {
        return node;
    }
    if (target < node->data) {
        return searchNode(node->left, target);
    }
    return searchNode(node->right, target);
}

int main() {
    Node* tree = NULL;
    tree = insertNode(tree, 4);
    tree = insertNode(tree, 2);
    tree = insertNode(tree, 6);
    tree = insertNode(tree, 3);
    tree = insertNode(tree, 5);
    tree = insertNode(tree, 1);
    tree = insertNode(tree, 7);

    printf("Tien thu tu:\t");
    preOrdered(tree);
    printf("\n");

    printf("Trung thu tu:\t");
    inOrdered(tree);
    printf("\n");

    printf("Hau thu tu:\t");
    postOrdered(tree);
    printf("\n");

    printf("Chieu cao cua cay: %d\n", treeHeight(tree));
    printf("So luong la: %d\n", countLeaves(tree));

    // T?m ki?m giá tr?
    int target;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &target);

    Node* result = searchNode(tree, target);
    if (result != NULL) {
        printf("Gia tri %d duoc tim thay trong cay.\n", target);
    } else {
        printf("Gia tri %d khong co trong cay.\n", target);
    }

    return 0;
}
