// T2 de Banco de DadosII 2025.2
// Aluno: Erickson G. Müller
// Mat: 20230001178
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct strTable{
	int id;
	char nome_logico[20];
	char nome_fisico[20];
};
typedef struct strTable tabela;

struct strAtt{
	int id; // atributo.id = tabela.id
	char nome[21]; // 21 usei 21 para caber o \0 mas talvez não precise
	char tipo;
	char opcionalidade;
	int tamanho;
};
typedef struct strAtt atributo;

int lerMetadados(FILE *FPTR, char *TABLENAME, tabela *TABELA){
	// verifica se existe alguma tabela com o nome em TABLENAME dentro do arquivo table.dic
	while (fread(TABELA, sizeof(tabela), 1, FPTR) == 1) {
			// Compara o nome da tabela fornecido (TABLENAME) com o nome lógico lido do arquivo.
			if(strcmp(TABLENAME, TABELA->nome_logico)==0){
				return 1; // "if(!lerMetad...
				//printf("%s",TABELA->nome_logico);
			}
		}
	return 0;
}
//void lerAtributos( int idTABELA){
//
// 	.------- DISCLAIMER -------.
// 	| Não consegui implementar |
// 	| 	essa função.	   |
// 	*--------------------------*
//
//	FILE *FPTR = fopen("att.dic", "rb");
//	if (FPTR == NULL){
//		printf("Não foi possível encontrar os metadados dos atributos");
//		return;
//	}
//	printf("att.dic: ");
//	int EXISTE_ATRIBUTO = 0;
//	atributo ATRIBUTO_DATA;
//	while(fread(&ATRIBUTO_DATA, sizeof(atributo), 1, FPTR) == 1){
//		if(ATRIBUTO_DATA.id == idTABELA){
//			if(EXISTE_ATRIBUTO > 0) {
//				printf(", ");
//			}
//			printf("<%d, \"%s\", '%c', %d>", ATRIBUTO_DATA.id, ATRIBUTO_DATA.nome, ATRIBUTO_DATA.tipo, ATRIBUTO_DATA.tamanho);
//			EXISTE_ATRIBUTO = 1; // Poderia usar um NUM_ATRIBUTOS++ caso seja necessário saber o número de atributos da tabela
//		}
//	}
//
//	if(EXISTE_ATRIBUTO > 0) {
//		printf("\n");
//	}
//	fclose(FPTR);
//}
int main(int argc, char *argv[]){
	// Verifica se o comando informa a tabela (POSTERIORMENTE VERIFICAR A EXTENSÃO INFORMADA)
	if (argc < 2) {
		printf("Número de argumentos insuficiente: ./main <datafile>\n");
		return 1;
	}
	if (argc > 2) {
		printf("Número de argumentos excede o necessário: ./main <datafile>\n");
		return 1;
	}


	char *TABLENAME = argv[1]; //'customer.dat'
	FILE *FPTR;
	FPTR = fopen("table.dic", "rb");// read binary
	if (FPTR == NULL) {
		printf("Não foi possível encontrar os metadados da tabela");
		return 1;
	}
	// verificar se o argv[1] existe em table.dic
	tabela TABELA;
	if (!lerMetadados(FPTR, TABLENAME, &TABELA)) {
		printf("Tabela '%s' nao encontrada em table.dic\n", TABLENAME);
		fclose(FPTR);
		return 1;
	}
	else{
		printf("table.dic: <%d, \"%s\", \"%s\">\n", TABELA.id, TABELA.nome_logico, TABELA.nome_fisico);
		//lerAtributos(TABELA.id);
	}

	fclose(FPTR);


	return 0;
}
