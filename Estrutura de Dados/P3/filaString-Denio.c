#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tdata {
	char c;
};
typedef struct tdata data;
struct tqueue {
	data info; // char info;
	struct tqueue *next;
};
typedef struct tqueue queue;
struct tsentqueue {
	queue *head; // first   
	queue *tail; // last
};
typedef struct tsentqueue squeue;
//
int emptyQueue(squeue s)
{
	// return (s.head == NULL);
	if (s.head==NULL) return 1; 
	return 0;
}
//int emptyQueue(squeue *s)
//{
//	// return (s->head == NULL);
//	if (s->head==NULL) return 1; 
//	return 0;
//}
//
void initQueue(squeue *s) 
{                              
	 s->head=NULL;            	
	 s->tail=NULL;          
}                          
//
void enQueue(squeue *s, data d)
{
	queue *f;
	f=(queue *)malloc(sizeof(queue)); //Passo 1
	f->info=d;   //Passo 2
	f->next=NULL; // Passo 2
	if (emptyQueue(*s)==1) { //emptyQueue(s)
		s->head=f; // Passo 3
		s->tail=f; // Passo 3
		return;
	}
	s->tail->next=f; // Passo 3
	s->tail=f; // Passo 3
	return;
}
//
data deQueue(squeue *s) {
	data d={'@'}; // valor representa erro
	queue *aux=s->head;
	if (emptyQueue(*s)==1) return d;
	d=s->head->info;
	s->head=s->head->next;
	free(aux);
	return d;
}
//
void freeQueue(squeue *s)
{
	queue *aux=s->head, *aux2;
	while (aux!=NULL)
	{
		aux2=aux;
		aux=aux->next;
		free(aux2);
    }
    initQueue(s);
    return;
}
//
int main()
{
	squeue s;
	data d;
	char *st={"Inserir na fila!"};
	int i;
	initQueue(&s);
	for (i=0;i<strlen(st);i++) {
		d.c=st[i];
		enQueue(&s,d);
	}
	while (emptyQueue(s)!=1)
	{
		d=deQueue(&s);
		printf("%c\n",d.c);
	}
	return 0;
}