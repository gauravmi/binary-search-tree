#define SUCCESS 1
#define FAILURE 0

struct Node{
	int data;	
	struct Node *left;
	struct Node *right;
};


struct Node* initializeTree(int number);
void traverseAndInsert(struct Node *node, struct Node **root);
void displayTree(struct Node *root);
int insertNode(int number, struct Node **tree);
int deleteNode(int number, struct Node **root);
void deleteWithChildren(struct Node **nodeToBeDeleted);
void search(int number, struct Node *root);

struct Node *root;

void displayTree(struct Node *root){
	int i;
	if(root==NULL){
		return;
	}	
	displayTree(root->left);
	printf("%d\n", root->data);
	displayTree(root->right);
}

void search(int number, struct Node *root){
	if(root==NULL){
		printf("not found : %d\n", number);
		return;
	}
	if(number == root->data){
		printf("found : %d\n", number);
		return;
	}else if(number <= root->data){
		search(number, root->left);
	}else{
		search(number, root->right);
	}	
}

void traverseAndInsert(struct Node *node, struct Node **root){
	if((*root)==NULL){
		(*root) = malloc(sizeof(struct Node));
		(*root)->data = node->data;
		(*root)->right = NULL;
		(*root)->left = NULL;
		return;
	}	
	if(node->data <= (*root)->data){
		traverseAndInsert(node, &(*root)->left);
	}else{
		traverseAndInsert(node, &(*root)->right);
	}
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

void deleteWithChildren(struct Node **nodeToBeDeleted){	
	free(*nodeToBeDeleted);
	*nodeToBeDeleted=NULL;
}

int insertNode(int number, struct Node **root){
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->data = number;
	newNode->left = NULL;
	newNode->right = NULL;
	traverseAndInsert(newNode, &(*root));
	return SUCCESS;
}

struct Node* initializeTree(int number){	
	root = malloc(sizeof(struct Node));
	root->data = number;
	root->left = NULL;
	root->right = NULL;
	return root;
}