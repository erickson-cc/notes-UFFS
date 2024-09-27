#include <stdio.h>
#include <stdlib.h>
#include <time.h>

				/* 
	---Lista--- 
.Estrutura dos nodes da lista
..Sentinela da lista
...Append_to_List
				*/
				//Declaração Lista
struct tlist{
	int valor;
	struct tlist* next;
};
typedef struct tlist nodelist;


struct listSent{
	nodelist *head, *tail;
};
typedef struct listSent list;

				//Operações Lista
void appendtoList(list *sent, int i){
	nodelist *aux;
	aux = (nodelist *)malloc(sizeof(nodelist));
	aux->valor = i;
	aux->next = NULL;

	if(sent->head==NULL){
		sent->head = aux;
		sent->tail = aux;
	}
	else{
		sent->tail->next = aux;
		sent->tail = aux;
	}
}

///////////////////////////////////


				/*
	---Fila--- 
.Estrutura dos nodes da fila
..Sentinela da fila
...Enqueue (direto da lista)
....Dequeue
				*/
				// Declaração Fila
struct tqueue{
	int valor; 
	struct tqueue *next;
};
typedef struct tqueue nodefila;

struct queueSent{
	nodefila *head, *tail;
};
typedef struct queueSent fila;
				//Operações Fila
///////////////////////////////////
void generateVector(int randomMin, int randomMax, int *vector){
	int randomNumber;
	int i;
	for(i=0;i<20;i++){
		randomNumber = randomMin+rand() % (randomMax-randomMin+1);
		vector[i] = randomNumber;
	}
}
	
int main(){
	int vector[20];
	generateVector(-100, 100, vector);
	int i;
	for(i=0;i<20;i++){
		printf(" %d ", vector[i]);
	}

		
	return 0;
}
