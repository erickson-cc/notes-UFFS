#include <stdio.h>
#include <stdlib.h>

struct dList{//struct do nó
	int num;
	struct dList *prev, *next;
};
typedef struct dList node;

struct listSent{//struct da arvore
	node *head,*tail;
};
typedef struct listSent sent;

void initList(sent *sent){
	sent->head = NULL;
	sent->tail = NULL;
}

void addTask(sent *sent, int num){
	node *aux;
	aux = (node *)malloc(sizeof(node));
	aux->num = num;
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

void printList(sent *sent){
	node *aux;
	
	for(aux=sent->head;aux!=NULL;aux=aux->next){
		printf("%d ",aux->num);
	}
	printf("\n");
}
int main(){
	sent sent;
	int num;
	
	initList(&sent);

	num = 3;
	addTask(&sent,num);
	printList(&sent);
	
	num = 4;
	addTask(&sent,num);
	printList(&sent);
	
	num = 77;
	addTask(&sent,num);
	printList(&sent);
	return 0;
}

