#ifndef BST_H
#define BST_H

typedef struct data{
	
	int value;
	
}Data;


typedef struct node{
	
	Data data;
	
	struct node *left;
	struct node *right;
	struct node *parent;
	
}Node;


typedef struct tree{
	
	Node *root;
	
	Data *(*insert)(struct tree *, Data);
	Data *(*search)(struct tree *, Data);
	
	struct tree *(*clone)(struct tree *);
	
	void (*sort)(struct tree *, Data *);
	void (*removeData)(struct tree *, Data);
	void (*delete)(struct tree*);
	
	int (*compare)(struct tree *, struct tree *);
	
}Tree;


Node *newNode(Data , Node *);
Node *insertBSTNode(Node *, Data);
Node *searchNode(Node *, Data);
Node *findMaxL(Node *);
Node *findMinR(Node *);
Node *deleteSearch(Tree *, Data);
Node *deleteSearchBSTNode(Node *, Data);

Tree *newTree();
Tree *clone(Tree *);

Data *insert(Tree *, Data);
Data *search(Tree *, Data);

void cloneBSTTree(Node *, Tree *);
void shortCircuit(Node *);
void sort(Tree *, Data *);
void inorder(Tree *);
void inOrder(Node *, Data *);
void inorderTreeTraversal(Node *);
void promotion(Node *);
void removeLeafNode(Node *);
void removeData(Tree *, Data);
void deleteNode(Node *);
void deleteTree(Tree *);
void deleteTreeFunction(Node *);

int sortTree(Node *, Data *, int);
int compare(Tree *, Tree*);
int compareBSTTreeNode(Node *, Node *);
int compareTreeNode(Node *, Node *, int);


#endif