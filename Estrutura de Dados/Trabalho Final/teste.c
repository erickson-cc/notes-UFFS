#include <stdio.h>

struct dList{//struct do nó
	int num;
	struct dList *prev, *next;
};
typedef struct dList node;

struct listSent{//struct da arvore
	node *head,*tail;
};
typedef struct listSent sent;

void printList(node *head){
	printf("printHead\n");
	for(head;head!=NULL;head=head->next){
		printf("%d ",head->num);
	}
}

int main(){
	sent *sent=NULL;
	sent->head=sent->tail = NULL;
	printList(&sent->head);
	
	return 1;
}

