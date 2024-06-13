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
	int command;
	task *tarefa, *aux, *first = NULL;

	printf("-------Sistema de Gerenciamento de Tarefas v1.0-----------\n");
	printf("Digite o número:\n");
	printf("1 - Adicionar Tarefa\n");
	printf("2 - Visualizar Tarefas\n");
	printf("3 - Finalizar Tarefa\n");
	printf("4 - Remover Tarefa\n");
	printf("0 - Encerrar Programa\n");
	
	scanf("%d",&command);
	if(command == 1){
		tarefa=(task *)malloc(sizeof(task));
		
		tarefa->id = 1;
		tarefa->note = 'H';
		tarefa->deadline = 10;
		tarefa->state = 0;

		if(first == NULL){
			first = tarefa;
			aux = tarefa;
		}
		else{
//			aux->next = tarefa;
			aux = tarefa;
		}

	}
}
int main(){
	mainMenu();
	return 0;
}
