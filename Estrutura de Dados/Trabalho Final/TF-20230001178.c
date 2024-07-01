#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode{
	int id;
	char note[20];
	int deadline;
	int state;

	struct listNode *prev, *next;
};
typedef struct listNode node;

struct listSent{
	node *head, *tail;
};
typedef struct listSent list;

void initList(list *sent){
	sent->head = NULL;
	sent->tail = NULL;
}

void addTask(list *sent, int i){//declarar a Task no main e alocar na função
	node *aux;
	aux = (node *)malloc(sizeof(node));
	aux->id = i;
	printf("Informe a Descrição da tarefa: ");
	scanf("%s",aux->note);
	printf("Informe o tempo para a conclusão da tarefa: ");
	scanf("%d",&aux->deadline);
	aux->state = 0;

	aux->next = aux->prev = NULL;

	if(sent->head==NULL){
		sent->head = aux;
		sent->tail = aux;
	}
	else{
		aux->prev = sent->tail;
		sent->tail->next = aux;
		sent->tail = aux;
	}
}
void finishTask(list *sent, int key){
	node *aux;
	for(aux=sent->head;aux!=NULL;aux=aux->next){
		if(aux->id == key){
			aux->state = 1;
			return;
		}
	}
		printf("ID não encontrado\n");
}


void removeTask(list *sent, int key){
	node *aux;
	for(aux=sent->head;aux!=NULL;aux=aux->next){
		if(aux->id == key){
			aux->prev->next = aux->next;
			aux->next->prev = aux->prev;
			free(aux);
			return;
		}
	}
		printf("ID não encontrado\n");
}

void printList(list *sent,int command){
	node *aux;
	if(command>3) return;
	if(command<0) return;
	if(command<=2){
		for(aux=sent->head;aux!=NULL;aux=aux->next){
			if(aux->state == 0){
				printf("(%d) ",aux->id);
				printf("%dh - ",aux->deadline);
				printf("%s\n",aux->note);
			}
		}
	}
	if(command%2!=0){
		for(aux=sent->head;aux!=NULL;aux=aux->next){
			if(aux->state == 1){
				printf("(%d) ",aux->id);
				printf("%dh - ",aux->deadline);
				printf("%s\n",aux->note);
			}
		}
	}
}


// 		state = 0 (ATIVA)
// 		state = 1 (CONCLUÍDA)
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
	list sent;
	int command=999;
	int i=0;
	int key;

	initList(&sent);

	//for(i=0;i<=5;i++){
	while(command!=0){
	mainMenu();
	scanf("%d",&command);
	if(command == 1){
		i = i+1;
		addTask(&sent, i);
	}
	if(command == 2){
		printf("-----Modo de visualização-----\n");
		printf("1 - Todas as Tarefas\n");
		printf("2 - Tarefas Ativas\n");
		printf("3 - Tarefas Concluídas\n");
		scanf("%d",&command);
		printList(&sent,command);
		command = 999;
	}
	if(command == 3){
		printf("Informe a ID da tarefa a ser finalizada\n");
		scanf("%d",&key);
		finishTask(&sent,key);
	}
	if(command == 4){
		printf("Informe a ID da tarefa a ser removida\n");
		scanf("%d",&key);
		removeTask(&sent,key);
	}
	}
	return 0;
}
