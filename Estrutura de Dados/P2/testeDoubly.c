#include <stdio.h>
#include <stdlib.h>

struct sxy {
 
   int x;
   int y;
   struct sxy *next, *prev;
};
typedef struct sxy txy;

struct stag {
   txy *head;
   txy *tail;
};

typedef struct stag ttag;

void init_lista(ttag *t)
{
	t->head=NULL;
	t->tail=NULL;
}
void incluir (ttag *t,int x, int y)
{	
	ttag *aux;
	aux = (ttag *)malloc(sizeof(ttag));
	
	aux->x = x;
	aux->y = y;	
	aux->next = NULL;
	aux->prev = NULL;

	aux->prev = last;
	last->next = aux;
	last =aux;
	
   return;
}

void consultar (ttag t,int x, int y)
{
	if (t.head==NULL)
	{	
		return;
    }
    return;
}

void excluir (ttag *t,int x, int y)
{
	if (t->head==NULL)
	{
    }
    return;
}

void lista_todos(ttag t)
{
	if (t.head==NULL)
	{
       return;
    }
	return;
}

int menu()
{
    int op;
    printf("1 - Incluir\n2 - Consultar\n3 - Excluir\n4 - Listar \n0 - Finalizar\n: ");
    scanf("%d",&op);
    return op;
}
//
int main()
{
   ttag tag;
   int op, x,y;
   init_lista(&tag);

   txy = *p, aux*, *first = NULL;

   op=menu();
   while (op!=0)
   {
      switch(op)
      {
         case 1: scanf("%d %d",&x,&y);
                 incluir(&tag,x,y);
                 break;
         case 2: scanf("%d %d",&x,&y);
                 consultar(tag,x,y);
                 break;
         case 3: scanf("%d %d",&x,&y);
                 excluir(&tag,x,y);
                 break;
         case 4: lista_todos(tag);
                 break;
      }
      op=menu();
   }

}
