#include <stdio.h>
#include <stdlib.h>
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

node *addTask(node *root, node *new){
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
	if(root==NULL){
		return;
	}
	showTasks(root->left);
	printf("%d ",root->tarefa.id);
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
	node *root=NULL, *new;
	int i;
	for(i=0;i<=5;i++){
	mainMenu();
	scanf("%d",&command);
	if(command == 1){
			new = (node *)malloc(sizeof(task));
		//tarefa=(task *)malloc(sizeof(task));
	
		tarefa.id = 1;
		tarefa.note = 'H';
		tarefa.deadline = 10;
		tarefa.state = 0;
	
		new->tarefa = tarefa;
		addTask(root, new);
	}
	if(command == 2){
		showTasks(root);
	}
	}
	return 0;
}
