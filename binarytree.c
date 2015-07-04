#include<stdio.h>
#include<stdlib.h>
#include "binarytree.h"

int main(){
	struct Node *root;
	root = initializeTree(8);
	insert(7, &root);
	insert(11, &root);
	insert(6, &root);
	insert(5, &root);
	insert(10, &root);
	
	delete(6, &root);
	
	search(8, root);
	search(7, root);
	search(11, root);
	search(6, root);
	search(5, root);
	search(10, root);
	displayTree(root);
	return SUCCESS;
}