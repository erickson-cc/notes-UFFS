/*
 * Faça um programa que receba uma string, caractere por caractere:
 * 	Cada caractere é colocado em uma fila
 * 	No fim da entrada, esvazia a fila imprimindo os caracteres armazenados
*/

#include <stdio.h>
#include <stdlib.h>

struct queue{
	char character;
	struct queue *next;
};
typedef struct queue q;

struct sentinela{
	struct queue head;
	struct queue tail;
};
typedef struct sentinela sent;

void initQueue(sent *queue){
	queue->head = NULL;
	queue->tail = NULL;
}
void enQueue(sent *queue, char character){
	q *aux;
	aux = (q *)malloc(sizeof(q));
	aux->char = character;
	aux->next = NULL;

	if(queue->head == NULL){
		queue->head = aux;
		queue->tail = aux;
	}
}
void deQueue(sent *queue, char *character){
	q *aux;
	if(queue->head == NULL){
		return
	}

	*character = queue->head->character;
	aux = queue->head;
	if(queue->head == queue->tail){
		queue->head = NULL;
		queue->tail = NULL;
	}
	else{
		queue->head = queue->head->next;
	}

	free(aux);
}

int main(){

	initQueue(queue);
}
