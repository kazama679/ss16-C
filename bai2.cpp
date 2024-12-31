#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;

// tao node moi
Node* createNode(int data){
	// cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// chen 1 nut vao cai cay
Node* insertNode(Node *node, int data){
	if(node == NULL){
		node = createNode(data);
	}
	if(data < node->data){
		node->left = insertNode(node->left, data);
	} else if(data > node->data) {
		node->right = insertNode(node->right, data);
	}
	return node;
}

// duyet cay theo pp tien thu tu
void preOrdered(Node* node){
	if(node != NULL){
		printf("%d \t", node->data);
		preOrdered(node->left);
		preOrdered(node->right);
	}
}

// trung thu tu
void inOrdered(Node* node){
	if(node != NULL){
		inOrdered(node->left);
		printf("%d \t", node->data);
		inOrdered(node->right);
	}
}

// hau thu tu
void postOrdered(Node* node){
	if(node != NULL){
		postOrdered(node->left);
		postOrdered(node->right);
		printf("%d \t", node->data);
	}
}

int main(){
	Node* tree = NULL;
	// insert
	tree = insertNode(tree, 4);
	tree = insertNode(tree, 3);
	tree = insertNode(tree, 6);
	tree = insertNode(tree, 2);
	tree = insertNode(tree, 5);
	
	printf("Tien thu tu:\t");
	preOrdered(tree);
	printf("\n");
	printf("Trung thu tu:\t");
	inOrdered(tree);
	printf("\n");
	printf("Hau thu tu:\t");
	postOrdered(tree);
	return 0;
}
