#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task{//(id,description,deadline,state=0) 
	int id;
	char note;	
	int deadline;
	int state;
};
typedef struct Task task;

struct binNode{
	task tarefa;
	struct binNode *left, *right;
};
typedef struct binNode node;

struct binTree{
	node *root;
};
typedef struct binTree tree;

void initTree(tree *tree){
	tree->root = NULL;
}
int searchID(tree *tree, int key){
	if(tree->root==NULL){
		return 0;
	}
	if(tree->root->tarefa.id == key){
		return 1;
	}
	if(tree->root->tarefa.id > key){
		tree->root = tree->root->left;
		return searchID(tree, key);
	}
	if(tree->root->tarefa.id < key){
		tree->root = tree->root->right;
		return searchID(tree, key);
	}
	return 0;
}

void addTask(node *root, node *new){
	if(root==NULL){
		root = new;
		return new;
	}
	if(root->tarefa.id>new->tarefa.id){
		root->left = addTask(root->left,new);
	}
	if(root->tarefa.id<new->tarefa.id){
		root->right = addTask(root->right,new);
	}
	return root;
}

void showTasks(node *root){
	printf("showTasks");
	if(root==NULL){
		return;
	}
	showTasks(root->left);
	printf("%s ",&root->tarefa.note);
	showTasks(root->right);
}
// 		state = 0 (ATIVA)
// 		state = 1 (CONCLUÍDA)
// task addTask
// task showTasks(any, state=1, state=0)
// 		sort 1-> state = 0
// 		if state = 0 -> deadline(0,inf)
// task concludeTask
// task popTask
// void mainMenu 
//
// BONUS - TAD .h & .c // binary tree (id)
void mainMenu(){
	
	printf("-------Sistema de Gerenciamento de Tarefas v1.0-----------\n");
	printf("Digite o número:\n");
	printf("1 - Adicionar Tarefa\n");
	printf("2 - Visualizar Tarefas\n");
	printf("3 - Finalizar Tarefa\n");
	printf("4 - Remover Tarefa\n");
	printf("0 - Encerrar Programa\n");
	
}
int main(){
	int command;
	task tarefa;
	tree tree;
	node *new;
	int i;
	tree->root = NULL;

	initTree(&tree);

	for(i=0;i<=5;i++){
	mainMenu();
	scanf("%d",&command);
	if(command == 1){
		new = (node *)malloc(sizeof(task));
		//tarefa=(task *)malloc(sizeof(task));
	
		tarefa.id = 1;
		printf("Descrição da tarefa\n");
		scanf("%s",&tarefa.note);
		//tarefa.note = 'H';
		printf("Deadline da tarefa\n");
		scanf("%d",&tarefa.deadline);
		//tarefa.deadline = 10;
		tarefa.state = 0;
	
		new->tarefa = tarefa;
		addTask(&tree.root, new);
	}
	if(command == 2){
		showTasks(&tree.root);
	}
	}
	return 0;
}
