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

//int main(){
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
int main(int argc, char *argv[]){
	// Verifica se o comando informa o arquivo .dat (POSTERIORMENTE VERIFICAR A EXTENSÃO INFORMADA)
	if (argc < 2) {
		printf("Número de argumentos insuficiente: ./main <datafile>\n");
		return 0;
	}

	char *tablename = argv[1];
	
	// variável char que imprime o documento no terminal
	char ch;
	// Cria o ponteiro para o arquivo
	FILE *fptr;
	fptr = fopen(tablename, "r");
	if (fptr == NULL) {
		printf("Erro: Não foi possível abrir o arquivo %s\n", tablename);
		return 0;
	}

	while ((ch = fgetc(fptr)) != EOF){
		// Colocar aqui dentro a interação com o arquivo
		int i;
		char metaname[15];
		char metatype;
		char metasize[4];
		//printf("%c", ch);
		for(i=0;i<15;i++){
			metaname[i] = fptr[i];
		}
		for(i;i<16;i++){
			metatype = fptr[i];
		}
		for(i;i<20;i++){
			metasize[i] = fptr[i];
		}
		printf("%s", metaname);
		printf("%c", metatype);
		printf("%s", metasize);

	}

	//fprintf(fptr, "%s", "teste");
	fclose(fptr);



	return 1;
}
