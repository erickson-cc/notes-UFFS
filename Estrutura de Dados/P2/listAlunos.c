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

	

int main(){

	Aluno *a, *aux, *first = NULL;

	int command=999;
	while(command != 0){
		printMenu();
		scanf("%d",&command);

		if(command == 1){
			a = (Aluno *)malloc(sizeof(Aluno));
			printf("Matrícula:"); scanf("%s",a->mat);
			printf("Nome:"); scanf("%s",a->name);
			a->bDay.day = 22;
		       	a->bDay.month=4;
			a->bDay.year = 2000;	
			a->nota=10;

			
			if (first == NULL){
				first = a;
			}
			for (aux=first;aux->next != NULL;aux=aux->next){
				aux->next = a;
				aux = a;
			}
		}
	}
	return 0;
}

