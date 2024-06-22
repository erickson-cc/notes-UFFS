#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node *next;
};
typedef struct Node node;

struct Pilha{
	node *top;
};
typedef struct Pilha pilha;

void initPilha(pilha *pilha){
	pilha->top = NULL;
}
void addNum(pilha *pilha, int num){
	node *aux;
	aux = (node *)malloc(sizeof(node));
	aux->next = NULL;
	aux->value = num;

	aux->next = pilha->top;
	pilha->top = aux;
}
void popTop(pilha *pilha, int *num){
	node *aux;
	
	*num = pilha->top->value;

	aux = pilha->top;
	pilha->top = pilha->top->next;
	free(aux);
}

int pilhaVazia(pilha *pilha){
	if(pilha->top==NULL){
		return 1;
	}
	return 0;
}

void limparPilha(pilha *pilha){
	node *aux;

	while(pilha->top!=NULL){
		aux=pilha->top;
		pilha->top=pilha->top->next;

		free(aux);
	}
}

int main(){
	pilha pilha;
	int num;
	num = 4;
	initPilha(&pilha);
	addNum(&pilha, num);
	return 0;
}

