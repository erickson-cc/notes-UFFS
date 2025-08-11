/*
 *
 *		Trabalho T1
 *	Pesquisa e Ordenação de Dados
 *	Erickson G. Müller
 *	Mat: 20230001178
 *	02 - Implemente a Ordenação Eficiente do Algoritmo quicksort.
 *	Ordenação: Quick Sort
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
				//Estrutura Lista
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
///////////////////////////////////
void createList(list *sent){
//Função seta a variável sentinela, declarada na Main
	sent->head = NULL;
	sent->tail = NULL;
}
void appendtoList(list *sent, int i){
//Adiciona um node com o valor i à lista
	nodelist *aux;
	aux = (nodelist *)malloc(sizeof(nodelist));
	aux->valor = i;
	aux->next = NULL;

	if(sent->head==NULL){//Verifica se a lista é vazia
		sent->head = aux;
		sent->tail = aux;
	}
	else{
		sent->tail->next = aux;
		sent->tail = aux;
	}
}
void printList(list *sent){
//Imprimir a Lista
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

				*/
				// Estrutura Fila
struct tqueue{
	int valor; 
	struct tqueue *next;
};
typedef struct tqueue nodefila;

struct queueSent{
	nodefila *head;
	nodefila *tail;
};
typedef struct queueSent fila;
				//Operações Fila
///////////////////////////////////

void enQueue(nodelist *listVector, fila *fsent){
//Função transforma um Vetor em Fila
	int i;
	nodefila *aux;
	fsent->head = NULL;//createFila()
	fsent->tail = NULL;//createFila()
	for(i=0;i<20;i++){//CALCULAR O TAMANHO DO VETOR
		aux = (nodefila *)malloc(sizeof(nodefila));
		aux->valor = listVector[i].valor;
		aux->next = NULL;
		if(fsent->head==NULL){//i=0
			fsent->head = aux;
		}
		else{
			fsent->tail->next = aux;
		}
		fsent->tail = aux;

	}
}
void printFila(fila *fsent){
//Imprimir Fila
	nodefila *aux;
	for(aux=fsent->head;aux!=NULL;aux=aux->next){
		printf(" %d ",aux->valor);
	}
}	

///////////////////////////////////
				//Operações Vetor
void generateVector(int randomMin, int randomMax, int *vector, int vectorLen){
//O vetor é gerado aleatóriamente
	int randomNumber;
	int i;
	for(i=0;i<vectorLen;i++){
		randomNumber = randomMin+rand() % (randomMax-randomMin+1);
		vector[i] = randomNumber;
	}
}
void vectorizeList(list *sent, nodelist *listVector){
//Transforma a Lista em Vetor
	listVector[0].valor = sent->head->valor;
	nodelist *aux;
	int i=0;
	for(aux=sent->head;aux!=NULL;aux=aux->next){
		listVector[i].valor = aux->valor;
		listVector[i].next = aux->next;
		i++;
	}
}
void printVector(int *vector, int vectorLen){
//Imprimir vetor de ints, para testes, precisa indicar o comprimento
	int i;
	for(i=0;i<vectorLen;i++){
		printf(" %d ", vector[i]);
	}
}
void printNodeVector(nodelist *listVector, int vectorLen){
//Imprime o vetor de Nodes
	int i;
	for(i=0;i<vectorLen;i++){
		printf(" %d ", listVector[i].valor);
	}
}
///////////////////////////////////
					/*
	--Quick Sort--
					*/
void troca(nodelist *pos1, nodelist *pos2){
	nodelist aux = *pos1;
	*pos1 = *pos2;
	*pos2 = aux;
}
int particiona(nodelist listVector[],int inicio,int fim){
	int pv;
	int k;
	int i;

	pv = fim;
	k = inicio;
	for(i=inicio;i<fim;i++){
		if(listVector[i].valor<=listVector[pv].valor){
			troca(&listVector[i], &listVector[k]);
			k++;
		}
	}

	if(listVector[k].valor>listVector[pv].valor){
		troca(&listVector[k], &listVector[pv]);
	}
	return pv;
}
void quickSort(nodelist listVector[], int inicio, int fim){
	if(fim>inicio){
		int posPivo;
		posPivo = particiona(listVector, inicio, fim);
		quickSort(listVector, inicio, posPivo-1);
		quickSort(listVector, posPivo+1, fim);
	}
}
///////////////////////////////////

int main(){
	//Declarações
	int i;
	int vectorLen=20;//Comprimento do Vetor
	nodelist listVector[vectorLen];//Vetor de nodelists
	fila fsent;//Sentinela da Fila
	list sent;//Sentinela da Lista
	
	//1-Criação do vetor
	int vector[] = {-59,76,3,69,-26,-54,-79,-88,-72,43,-23,-95,66,44,12,-11,81,-17,-97,-91};
	printf("\nVetor Inicial:\n"); //TESTE
	printVector(vector, vectorLen);// TESTE
	
	//2-Criação da Lista
	createList(&sent);	
	for(i=0;i<vectorLen;i++){
		// o loop está fora da função pois appendtoList não é uma função de transformar vetor em lista
		appendtoList(&sent,vector[i]);
	}
	printf("\nLista encadeada não ordenada:\n");//TESTE
	printList(&sent);//TESTE
	
	//3-Passar da Lista para o Vetor
	vectorizeList(&sent, listVector);//Transforma a Lista em Vetor
	
	//4-Ordenação do vetor
	quickSort(listVector, 0, vectorLen-1);// Ordena o Vetor
	printf("\n Vetor ordenado:\n");//TESTE
	printNodeVector(listVector,20);//TESTE
	
	//5-Passar do Vetor para a Fila
	enQueue(listVector,&fsent);//Transforma o vetor em fila
	printf("\n Fila ordenada:\n");//TESTE
	printFila(&fsent);//TESTE

	return 0;
}
