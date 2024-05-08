#include <stdio.h>
#include <stdlib.h>

struct tt {
  int value;
  struct tt *next;
};

typedef struct tt myt;

// inserção, percorrer até o último para encadeamento
myt *insertElement(myt *f, int v) {
  myt *aux;
  myt *lInt = (myt *)malloc(sizeof(myt));
  lInt->value = v;
  lInt->next = NULL;
  if (f == NULL) 
    return lInt;
  for (aux = f; aux->next != NULL; aux = aux->next);
  aux->next = lInt;
  return lInt;
}
//
void freeMemory(myt *f)
{
  myt *aux, *aux2;
  aux=f;
  while (aux!=NULL)
    {
      aux2=aux;
      aux=aux->next;
      free(aux2);
    }
}
//
myt *getIntersection(myt *l1, myt *l2)
{
  myt *aux1, *aux2;
  myt *f=NULL, *l, *aux; 
  n1n1for (aux1=l1;aux1!=NULL;aux1=aux1->next)
  { 
    for(aux2=l2;aux2!=NULL;aux2=aux2->next)
    {
       if (aux1->value==aux2->value)
       {
         // passo 1
         l=(myt *)malloc(sizeof(myt));
         // passo 2
         l->value=aux1->value;
         l->next=NULL;
         // passo 3
         if (f==NULL)
         {
           f=l;
           aux=l;
         } else {
           aux->next=l;
           aux=l;
         }  
       }
    }
  }
  return f;
}
//
void showList (myt *f)
{
  myt *aux;
  for (aux=f;aux!=NULL;aux=aux->next)
    printf("Valor: %d\n", aux->value);
}
//
int main() {
  myt *fl1 = NULL, *fl2=NULL, *fl3=NULL;
  myt *l1, *l2;
  // carrega lista 1
  l1 = insertElement(fl1, 10);
  if (fl1 == NULL){
      fl1 = l1;
  }
  l1 = insertElement(fl1, 15);
  l1 = insertElement(fl1, 20);
  ////carrega lista 2
  l2 = insertElement(fl2, 20);
  if (fl2 == NULL) {
      fl2 = l2;
  }
  l2 = insertElement(fl2, 10);
  l2 = insertElement(fl2, 15);
  printf("Lista 1: \n");
  showList(fl1);
  printf("Lista 2: \n");
  showList(fl2);
/// coloque aqui a interseção
  fl3=getIntersection(fl1,fl2);
  printf("Interseção: \n");
  showList(fl3);
  freeMemory(fl1);
  freeMemory(fl2);
  freeMemory(fl3);
  return 0;
}

