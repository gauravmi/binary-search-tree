struct Node{
	int data;	
	struct Node *left;
	struct Node *right;
};


int initializeTree(int number, struct Node **root);
void traverseAndInsert(struct Node **node, struct Node **root);
void displayTree(struct Node **root);
int insertNode(int number, struct Node **tree);