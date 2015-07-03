struct Node{
	int data;	
	struct Node *left;
	struct Node *right;
};


int initializeTree(int number, struct Node **root);
void traverseAndInsert(struct Node **node, struct Node **root);
void displayTree(struct Node **root);
int insertNode(int number, struct Node **tree);
int deleteNode(int number, struct Node **root);
void deleteWithChildren(struct Node **nodeToBeDeleted);
void search(int number, struct Node **root);