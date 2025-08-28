#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct strAtr{
	char nome[16];
	char tipo;
	char tamanho;
};
typedef struct strAtr atributo;
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
	fptr = fopen(tablename, "rb");// read binary
	if (fptr == NULL) {
		printf("Erro: Não foi possível abrir o arquivo %s\n", tablename);
		return 0;
	}
	atributo atributos[10];
	int count = 0;

	while (count<10){
		atributo currAtributo;
		// Lê os 15 primeiro bytes do atributo (nome)
		if (fread(currAtributo.nome, sizeof(char), 15, fptr) != 15) {
			break;
		}
		currAtributo.nome[15] = '\0'; // Adiciona um null terminator

		// Lê o byte do tipo
		if (fread(currAtributo.tipo, sizeof(char), 1, fptr) != 1){
			break;
		}
		// Lê o byte do tamanho
		if (fread(currAtributo.tamanho, sizeof(char), 4, fptr) != 4){
			break;
		}

		strcpy(atributos[count].nome, currAtributo.nome);
		strcpy(atributos[count].tipo, currAtributo.tipo);
		strcpy(atributos[count].tamanho, currAtributo.tamanho);
		count++;
	}
	printf("Header da tabela: '%s'\n\n", tablename);
	for(int i =0; i<count;i++){
		printf("Título: %s\n", atributos[i].nome);
		printf("Tipo: %s\n", atributos[i].tipo);
		printf("Tamanho: %s\n", atributos[i].tamanho);
	}

	//fprintf(fptr, "%s", "teste");
	fclose(fptr);
	return 1;
}
