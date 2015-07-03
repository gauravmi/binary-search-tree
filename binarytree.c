#include<stdio.h>
#include<stdlib.h>
#include "binarytree.h"
#define SUCCESS 1
#define FAILURE 0

int main(){
	struct Node *root = malloc(sizeof(struct Node));
	initializeTree(8, &root);
	insertNode(7, &root);
	insertNode(11, &root);
	insertNode(6, &root);
	insertNode(5, &root);
	insertNode(10, &root);
	displayTree(&root);
	printf("before..\n");
	deleteNode(6, &root);
	printf("after..\n");
	displayTree(&root);
	return SUCCESS;
}

void displayTree(struct Node **root){
	int i;
	if((*root)==NULL){
		return;
	}
	displayTree(&(*root)->left);
	printf("%d\n", (*root)->data);
	displayTree(&(*root)->right);
}

void traverseAndInsert(struct Node **node, struct Node **root){
	if(*root==NULL){
		*root = malloc(sizeof(struct Node));
		(*root)->left = malloc(sizeof(struct Node));
		(*root)->right = malloc(sizeof(struct Node));
		(*root)->data = (*node)->data;
		(*root)->right = NULL;
		(*root)->left = NULL;
		return;
	}
	if((*node)->data <= (*root)->data){
		traverseAndInsert(node, &((*root)->left));
	}else{
		traverseAndInsert(node, &((*root)->right));
	}
}
void deleteWithChildren(struct Node **nodeToBeDeleted){
	*nodeToBeDeleted=NULL;	
}

int deleteNode(int number, struct Node **root){
	if(number == (*root)->data){
		deleteWithChildren(root);
		return SUCCESS;
	}
	if(number <= (*root)->data){
		deleteNode(number, &((*root)->left));
	}else{
		deleteNode(number, &((*root)->right));
	}
	return FAILURE;
}

int insertNode(int number, struct Node **root){
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->data = number;
	newNode->left = NULL;
	newNode->right = NULL;
	traverseAndInsert(&newNode, root);
	return SUCCESS;
}

int initializeTree(int number, struct Node **root){	
	(*root)->data = number;
	(*root)->left = NULL;
	(*root)->right = NULL;
	return SUCCESS;
}