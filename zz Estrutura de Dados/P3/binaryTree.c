#include <stdio.h>
#include <stdlib.h>
// Cria uma árvore binária com as deadlines das tarefas
struct Tempo{
	int horas;
	int minutos;
};
typedef struct Tempo tempo;

struct binNode{
	tempo deadline;//estrutura tempo dentro da estrutura node
	struct binNode *left, *right;
};
typedef struct binNode node;

node *insertNode(node *root, node *new){//Inserir Recursiva
	// Primeiro item a ser inserido
	if(root==NULL){
		root = new;//Talvez colocar um root = new aqui
		return new;
	}
	// Se o Root for maior que o new: seguir à esquerda
	// Vai criando subárvores em que root->dir = root
	if(60*root->deadline.horas+root->deadline.minutos>60*new->deadline.horas+new->deadline.minutos){
		root->left = insertNode(root->left,new);
	}
	// Se o Root for menor que o new: seguir à direita
	if(60*root->deadline.horas+root->deadline.minutos<60*new->deadline.horas+new->deadline.minutos){
		root->right = insertNode(root->right,new);
	}
	// Retorna o root ao final
	return root;
}

void printTree_Transversal(node *root){
	if(root==NULL){
	return;
	}
		//printf("%d",root->deadline.horas);// vai imprimir na ordem de inserção
	printTree_Transversal(root->left);
	printf("%d",root->deadline.horas);// vai imprimir em ordem crescente
	printTree_Transversal(root->right);
		//printf("%d",root->deadline.horas);//vai imprimir de trás para frente na ordem de inserção

}
int main(){
	
	node *root = NULL;//root global
	node *new;	//Como se fosse o aux

	int i;

	for(i=0;i<4;i++){
		new = (node *)malloc(sizeof(node));
		printf("Diga as horas do %d node", i+1);
		scanf("%d",&new->deadline.horas);
		
		printf("Diga os minutos do %d node", i+1);
		scanf("%d",&new->deadline.minutos);
		
		new->left=NULL;
		new->right=NULL;
		root=insertNode(root,new);
	}
	printTree_Transversal(root);

	return 0;
}
