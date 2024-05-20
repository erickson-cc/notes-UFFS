#include <stdio.h>
#include <stdlib.h>
//matrícula = char[10]
//nome = char[40]
//bDay = struct Data 
//média = float
//Função incluir
//Função excluir - através da matrícula informada
//Função listar "MAT, nome, bDay, média" / ordem de inserção
//Função listar inversa
//Função contar o número de elementos numa lista = int
//menu
//	1 - incluir elemento
//	2 - excluir elemento
//	3 - listar em ordem de inclusão
//	4 - listar em ordem inversa
//	5 - quantidade de alunos
//	0 - sair do programa 
 
struct Date{
	int day, month, year;
};
typedef struct Date Data;

struct Student{
	int id;
	char  mat[10];
	char name[40];
	Data bDay;
	float nota;
	struct Student *next;//Testar com Aluno
};
typedef struct Student Aluno;

void printMenu(){
	printf("-----------Lista de Alunos UFFS-----------\n");
	printf(" 1 - CADASTRAR NOVO ALUNO\n");
	printf(" 2 - EXCLUIR ALUNO\n");
	printf(" 3 - LISTAR ALUNOS POR ORDEM DE MATRÍCULA\n");
	printf(" 4 - LISTAR ALUNOS POR ORDEM INVERSA\n");
	printf(" 5 - VER QUANTIDADE DE ALUNOS MATRICULADOS\n");
}
Aluno *delAluno(Aluno *first, int id){
	Aluno *aux, *previous;
	for(aux=first;aux!=NULL;aux=aux->next){
		if (aux->id == id){
			if(aux==first){
				first = first->next;
				break;
			}
			previous->next=aux->next;
			break;
		}
		previous = aux;
	}
	if(aux!=NULL){ 
		free(aux);
	}
	return first;
	}
	

int main(){

	Aluno *a, *aux, *first = NULL;
	int id=0; 
	int delid;

	int command=999;
	while(command != 0){
		printMenu();
		scanf("%d",&command);
			
		if(command == 1){
			a = (Aluno *)malloc(sizeof(Aluno));
			id = id+1;
			a->id = id;
			printf("Matrícula:"); scanf("%s",a->mat);
			printf("Nome:"); scanf("%s",a->name);
			a->bDay.day = 22;
		       	a->bDay.month=4;
			a->bDay.year = 2000;	
			a->nota=10;

			
			if (first == NULL){
				first = a;
				aux = a;
			}
			else{
				aux->next = a;
				aux = a;
			}
		}
		if(command == 2){
			printf("ID: "); scanf("%d",&delid);
			delAluno(Aluno *first, int delid);
		}
		if(command == 3){
			for(aux=first;aux!=NULL;aux=aux->next){
				printf("Matrícula: %s\n",aux->mat);
				printf("Nome: %s\n",aux->name);
				printf("Aniversário = %d/%d/%d\n",aux->bDay.day,aux->bDay.month,aux->bDay.year);
				printf("Nota: %f\n",aux->nota);
				printf("ID: %d\n\n",aux->id);
			}
		}
	}
	return 0;
}

