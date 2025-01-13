/*
 *
 *		Trabalho T1
 *	Pesquisa e Ordenação de Dados
 *	Erickson G. Müller
 *	Mat: 20230001178
 *	01 - Implemente uma ordenação ineficiente a sua escolha:
 *	Ordenação: Selection Sort
 *
*/

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
void createList(list *sent){
	sent->head = NULL;
	sent->tail = NULL;
}
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
void printList(list *sent){
	nodelist *aux;
	for(aux=sent->head;aux!=NULL;aux=aux->next){
		printf(" %d ", aux->valor);
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

				//Operações Vetor
void generateVector(int randomMin, int randomMax, int *vector, int vectorLen){
	int randomNumber;
	int i;
	for(i=0;i<vectorLen;i++){
		randomNumber = randomMin+rand() % (randomMax-randomMin+1);
		vector[i] = randomNumber;
	}
}

void printVector(int *vector, int vectorLen){
	int i;
	for(i=0;i<vectorLen;i++){
		printf(" %d ", vector[i]);
	}
}

///////////////////////////////////
					/*
	--Selection Sort--
				 */
void insertionSort(list *sent){
	nodelist *lord; //last ordered
	nodelist *ins;
	nodelist *aux;
	lord=sent->head
	for(ins=lord->next;ins!=NULL;ins=ins->next){
		for(aux=sent->head;aux->next->valor<ins->valor;aux=aux->next){
			if(aux->next->valor>ins->valor){
				lord->next=lord->next->next;
				ins->next=aux->next;
				aux->next = ins;
			}
		}
	}
}
int main(){
	int vectorLen;
	vectorLen = 20;
	int vector[vectorLen];
	generateVector(-100, 100, vector, vectorLen);
	printf("\nVetor Inicial:\n");
	printVector(vector, vectorLen);

	list sent;	
	createList(&sent);
	int i;
	for(i=0;i<vectorLen;i++){
		appendtoList(&sent,vector[i]);
	}
	printf("\nLista encadeada não ordenada:\n");
	printList(&sent);
	printf("%d",sent.tail->valor);
	
	insertionSort(&sent);
	printf("\n Lista encadeada ordenada:\n");
	printList(&sent);
	return 0;
}
