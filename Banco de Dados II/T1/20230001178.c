#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct strAtr{
//	char nome[15];
//	char tipo;
//	int tamanho;
//};
//typedef struct strAtr atributo;
//
//struct strHeader{
//	atributo *campo;
//};
//typedef strHeader header;

//int existeArquivo(const char* filename){
//
//    char directory[LEN_DB_NAME_IO];
//    strcpy(directory, connected.db_directory);
//    strcat(directory, filename);
//    FILE* fptr = fopen(directory, "r");
//
//    if (fptr != NULL){
//        fclose(fptr);
//
//        return 1;
//    }
//
//    return 0;
//}

int main(){
	// Armazenar nos bytes iniciais o esquema de dados
	// HEADER:
	// 	Primeiros 15 bytes representam o nome do atributo (string)
	//	O byte seguinte do tipo char poder ser 'C', 'S', 'I' ou 'F' 
	//	Em seguida um inteiro que armazena o tamanho do atributo:
	//		Para numéricos, usar sizeof()
	// O cabeçalho terá uma sequência de atributos (no máximo 10).
	// Caso existirem menos de 10, o nome do atributo que delimita é #, ou seja, basta testar nome[0]!='#' para saber que a sequência do atributo é válida.
	// gerar um relatório:
	// 	att1	att2	att3	att4
	//	----	----	----	----
	// 	val1	val2	val3	val4
	// 	val1	val2	val3	val4
	// 	val1	val2	val3	val4
	// 	val1	val2	val3	val4
	
	
	// variável char que imprime o documento no terminal
	char ch;
	// Cria o ponteiro para o arquivo
	FILE *fptr;
	fptr = fopen("customer.dat", "r");
	while ((ch = fgetc(fptr)) != EOF){
		printf("%c", ch);
	}

	//fprintf(fptr, "%s", "teste");
	fclose(fptr);



	return 1;
}
