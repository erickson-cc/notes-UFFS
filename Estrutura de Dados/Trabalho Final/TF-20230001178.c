#include <stdio.h>
#include <stdlib.h>
struct Task{//(id,description,deadline,state=0) 
	int id;
	char note;	
	int deadline;
	int state;
	struct Task *next;
};
typedef struct Task task;

task *addTask(task *tarefa, task *first){
	task *aux;
	if (first == NULL){
		first = tarefa;
		return first;
	}
	for (aux = first; aux->next!=NULL;aux=aux->next);
	aux->next=tarefa;
	return first;
}
task *showTask(task *first){
	task *aux;
	if(first!=NULL){
		for(aux=first;aux!=NULL;aux=aux->next){
			printf("%d ",aux->id);
				
		}
	}
	return first;
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
	task *tarefa, *first = NULL;
	int i;
	for(i=0;i<=5;i++){
	mainMenu();
	scanf("%d",&command);
	if(command == 1){
		tarefa=(task *)malloc(sizeof(task));
		
		tarefa->id = 1;
		tarefa->note = 'H';
		tarefa->deadline = 10;
		tarefa->state = 0;

		addTask(tarefa, first);
	}
	if(command == 2){
		showTask(first);
	}
	}
	return 0;
}
