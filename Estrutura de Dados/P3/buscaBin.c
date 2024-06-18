#include <stdio.h>
#include <stdlib.h>
#include <time.h> // random stuffs

#define COUNT 5

struct ttree {
	int value;
	struct ttree *left, *right;
};
typedef struct ttree tree;


//tarefa vvvvvvvvvvvvv
tree *getNode(tree *r, int key){
	if (r==NULL){
		return r;
	}
	else{
		if(r->value==key){
			return r;
		}
		if(r->value<key){
			return getNode(r->right, key);
		}
		if(r->value>key){
			return getNode(r->left, key);
		}
	}
	return r;//Meio inútil
}
//tarefa ^^^^^

void print2DUtil(tree *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(tree *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
//////
void inOrder(tree *n)
{
}
/////
void preOrder(tree *n)
{
}
////
void posOrder(tree *n)
{
}
////
tree *insertNodeR (tree *root, tree *n)
{
	if (root==NULL) return n;
	if (n->value <= root->value)
	    root->left=insertNodeR(root->left,n);
	else
	    root->right=insertNodeR(root->right,n);
	return root;
}
////
tree *insertNodeI (tree *root, tree *n)
{
	tree *auxt, *parent=NULL;
	int dir; // stores the side to insert the node (0 left 1 right)
	if (root==NULL) return n;
	auxt=root;
	while (auxt!=NULL)
	{
		parent=auxt; // parent stores the parent's pointer
		if (n->value <= auxt->value) // go to the left
		{
			auxt=auxt->left;
			dir=0;
		} else {
			auxt=auxt->right;
			dir=1;
        }
    }
    if (dir==0) parent->left=n;
    else        parent->right=n;
    return root;
}
////
int main()
{
	tree *root=NULL, *nodo;//, *root2=NULL;
	int v, i;//, dir;
    srand(time(NULL));
	for (i=0;i<10;i++)
	{
		v=rand()%100; // sorteia números entre 0 e 999
		nodo=(tree *)malloc(sizeof(tree));
		nodo->value=v;
		nodo->left=NULL;
		nodo->right=NULL;
		root=insertNodeR(root,nodo);
		//root=insertNodeI(root,nodo);
    }
    print2D(root);
	return 0;
}
