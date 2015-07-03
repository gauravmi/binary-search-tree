#include<stdio.h>
#include<stdlib.h>
#include "binarytree.h"

int main(){
	struct Node *root = malloc(sizeof(struct Node));
	initializeTree(8, &root);
	insertNode(7, &root);
	insertNode(11, &root);
	insertNode(6, &root);
	insertNode(5, &root);
	insertNode(10, &root);	
	deleteNode(6, &root);
	search(8, &root);
	search(7, &root);
	search(11, &root);
	search(6, &root);
	search(5, &root);
	search(10, &root);
	displayTree(&root);
	return SUCCESS;
}
