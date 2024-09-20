#include <stdio.h>

/* ---Lista--- */
struct tlist{
	int valor;
	struct tlist *next;
};
typedef struct tlist listnode;

struct listSent{
	listnode *head, *tail;
};
typedef struct listSent sent;

/* ---Fila--- */
struct tqueue{
	int valor; 
	struct tqueue *next;
};
typedef struct tqueue queuenode;

void addNode(list *sent, int i){
	list *aux;
	aux = (list *)malloc(sizeof(list));
}

void printList(sent *head){
	list *aux;
	for(aux=sent->head;aux!=NULL;aux=aux->next){
		printf("%d",aux->valor);
	}
}
int main(){
	vetor = [-12,34,-7,0,67,-32,89,5,-23,99,-1,42,-50,10,-27,81,-3,65,44,37];
	for(i=0;i<20;i++){
		printf("%d",vetor[i]);
	}
	return 0;
}
