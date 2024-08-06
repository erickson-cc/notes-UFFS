#include <stdio.h>
#include <stdlib.h>

struct Fila{
	char letra;
	struct Fila *next;
};
typedef struct Fila fila;

fila *addChar(fila *head, fila *tail, char new){
	fila *aux;
	aux = (fila *)malloc(sizeof(fila));
	printf("Informe o novo Char\n");
	scanf("%s",&new);
	aux->letra = new;
	aux->next = NULL;

	if(head==NULL){
		head=aux;
		tail=aux;
	}
	else{
		tail->next=aux;
		tail=aux;
	}
	printf("Primeiro = %s\n",&head->letra);
	printf("Ultimo = %s\n",&tail->letra);
	return head;
}

void popChar(fila *head,fila *tail){
	fila *aux;
	aux=head;
	if(head==tail){
		head=NULL;
		tail=NULL;
	}
	else{
		head=head->next;
	}
	free(aux);
	return;
}

void printChar(fila *head, fila *tail){ printf("O primeiro char da fila = %s\n",&head->letra);
	printf("O ultimo char da fila = %s\n",&tail->letra);
	return;
}

void menu(int encerrar, fila *head, fila *tail, char new){
	while(encerrar){
		int command;
		printf("1 - inserir item ao final\n");
		printf("2 - popar primeiro da fila \n");
		printf("3 - imprimir primeiro e ultimo da fila\n");
		printf("0 - encerrar programa\n");
		
		scanf("%d",&command);
		if(command==1){
				head = addChar(head, tail, new);
		}
		if(command==2){
			popChar(head, tail);
		}
		if(command==3){
			printChar(head, tail);
		}
		if(command==0){
			encerrar = 0;
		}
	}
	return;
}

int main(){
	
	fila *head, *tail;
	//&head = NULL;
	//&tail = NULL;
	char new='c';
	int encerrar=1;
	menu(encerrar, &head, &tail, new);
	return 1;
}



