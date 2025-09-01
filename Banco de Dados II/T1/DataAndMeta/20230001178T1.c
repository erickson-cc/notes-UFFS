// T1 de Banco de DadosII 2025.2
// Aluno: Erickson G. Müller
// Mat: 20230001178
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct strAtr{
	char nome[16]; // 15 + 1 para o '\0'
	char tipo;
	int tamanho;
};
typedef struct strAtr atributo;

int lerHeader(FILE *FPTR, atributo ATRIBUTOS[]){
	//Função serve para contar o número de atributos de uma tabela
	//e armazenar na variável NUM_ATRIBUTOS ao mesmo tempo que ar-
	//mazena os atributos na variável ATRIBUTOS
	int NUM_ATRIBUTOS = 0;
	while(NUM_ATRIBUTOS<10){ // Verificar enunciado
		long POSITION = ftell(FPTR); //Serve para ajustar a posição após encontrar o '#'
		fread(ATRIBUTOS[NUM_ATRIBUTOS].nome, sizeof(char), 15, FPTR);
		ATRIBUTOS[NUM_ATRIBUTOS].nome[15] = '\0'; //Encerrar a string
		
		if(ATRIBUTOS[NUM_ATRIBUTOS].nome[0] == '#'){
			// Fim do header
			fseek(FPTR, POSITION+1, SEEK_SET); //Ajusta a posição
			break;
		}	
		fread(&ATRIBUTOS[NUM_ATRIBUTOS].tipo, sizeof(char), 1, FPTR);
		fread(&ATRIBUTOS[NUM_ATRIBUTOS].tamanho, sizeof(int), 1, FPTR);
		NUM_ATRIBUTOS++;
	}
	return NUM_ATRIBUTOS;
}

void printHeader(atributo ATRIBUTOS[], int NUM_ATRIBUTOS){
	int i;
	for(i=0; i<NUM_ATRIBUTOS; i++){
		printf("%-20s",ATRIBUTOS[i].nome); //Alinhamento 20 chars;
						   //para melhor visualização
	}
	printf("\n");
}

void printTuple(FILE *FPTR, atributo ATRIBUTOS[], int NUM_ATRIBUTOS){
	// Função para imprimir uma linha de dados da tablea
	// percorre a tupla a partir do ponteiro do arquivo FPTR
	long START_TUPLE = ftell(FPTR);
	fseek(FPTR, 0, SEEK_END); //Move o ponteiro para o final para 
				  //descobrir o tamanho total
	long SIZE_FILE = ftell(FPTR); //Armazena o tamanho total
	fseek(FPTR, START_TUPLE, SEEK_SET); //e retorna para o i início
	int i;

	while(ftell(FPTR)<SIZE_FILE){
		for(i=0;i<NUM_ATRIBUTOS;i++){
			switch(ATRIBUTOS[i].tipo){
				// Reconhecer o tipo do atributo 
				case 'S': {
				    char *STRING_VALUE = (char *)malloc(ATRIBUTOS[i].tamanho + 1);
				    fread(STRING_VALUE, sizeof(char), ATRIBUTOS[i].tamanho, FPTR);
				    STRING_VALUE[ATRIBUTOS[i].tamanho] = '\0'; //fim da string
				    printf("%-20s", STRING_VALUE);
				    free(STRING_VALUE);
				    break;
				}
				case 'C': {
				    char CHAR_VALUE;
				    fread(&CHAR_VALUE, sizeof(char), 1, FPTR);
				    printf("%-20c", CHAR_VALUE);
				    break;
				}
				case 'I': {
				    int INT_VALUE;
				    fread(&INT_VALUE, sizeof(int), 1, FPTR);
				    printf("%-20d", INT_VALUE);
				    break;
				}
				case 'F': {
				    float FLOAT_VALUE;
				    fread(&FLOAT_VALUE, sizeof(float), 1, FPTR);
				    printf("%-20.2f", FLOAT_VALUE); // Imprime em 2 casas decimais (Altura/Salário)
								    //
				    break;
				}
			}
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]){
	// Verifica se o comando informa o arquivo .dat (POSTERIORMENTE VERIFICAR A EXTENSÃO INFORMADA)
	if (argc < 2) {
		printf("Número de argumentos insuficiente: ./main <datafile>\n");
		return 1;
	}
	if (argc > 2) {
		printf("Número de argumentos excede o necessário: ./main <datafile>\n");
		return 1;
	}

	
	// variável char que imprime o documento no terminal
	//char ch;
	// Cria o ponteiro para o arquivo
	char *TABLENAME = argv[1]; //'customer.dat'
	FILE *FPTR;
	FPTR = fopen(TABLENAME, "rb");// read binary
	if (FPTR == NULL) {
		printf("Erro: Não foi possível abrir o arquivo %s\n", TABLENAME);
		return 1;
	}

	// Aqui serão armazenados os atributos da tabela
	atributo ATRIBUTOS[10];
	int NUM_ATRIBUTOS = lerHeader(FPTR, ATRIBUTOS);
	printHeader(ATRIBUTOS, NUM_ATRIBUTOS);
	printTuple(FPTR, ATRIBUTOS, NUM_ATRIBUTOS);


	fclose(FPTR);
	return 0;
}

// ----------- LIXÂO DE CÒDIGO -------------------
	// gcc -Wall 20230001178.c -o main.out
	//
	// Armazenar nos bytes iniciais o esquema de dados
	// HEADER:
	// 	Primeiros 15 bytes representam o nome do atributo (string)
	//	O byte seguinte do tipo char poder ser 'C', 'S', 'I' ou 'F' 
	//	Em seguida um inteiro que armazena o tamanho do atributo:
	//		Para numéricos, usar sizeof()
	// O cabeçalho terá uma sequência de ATRIBUTOS (no máximo 10).
	// Caso existirem menos de 10, o nome do atributo que delimita é #, ou seja, basta testar nome[0]!='#' para saber que a sequência do atributo é válida.
	// gerar um relatório:
	// 	att1	att2	att3	att4
	//	----	----	----	----
	// 	val1	val2	val3	val4
	// 	val1	val2	val3	val4
	// 	val1	val2	val3	val4
	// 	val1	val2	val3	val4
