#include <stdio.h>
#include <stdlib.h>

struct tpoint{
	int x,y;
	struct tpoint *next;
};
typedef struct tpoint tpnt;
void free_memory(tpnt *p){
	if(p==NULL) return;
	free_memory(p->next);
	free(p);
}

tpnt *ins_end(tpnt *f, tpnt *p){
	tpnt *aux;
	if (f==NULL){
		f=p;
		return f;
	}
	for(aux=f;aux->next!=NULL;aux=aux->next);
	aux->next=p;
	return f;
}

int main(){
	tpnt *p, *aux, *first = NULL;
	int i;
	for(i=1;i<=10;i++){
		// passo 1 alloc
		p = (tpnt *)malloc(sizeof(tpnt));
		// segundo passo encadeamento
		p->x=i;
		p->y=i+10;
		// terceiro passo encadear
		if (first==NULL){
			first = p;
			aux = p;
		}
		else{
			aux->next = p;
			aux = p;
		}
	}
	
	// printando
	for (aux=first;aux!=NULL;aux=aux->next){
	printf("(%d,%d)\n",aux->x,aux->y);
	}
	// usando o free recursivamente
	if (first!=NULL){
		aux=first;
		while(aux->next!=NULL){
			p=aux;
			aux = aux->next;
			free(p);
		}
		//último
		free(aux);
		first=NULL;
	}

	return 0;
}

