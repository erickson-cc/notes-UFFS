#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	struct strAtr{
		char nome[15];
		char tipo;
		int tamanho;
	};
	typedef struct strAtr atributo;
	
	struct strHeader{
		atributo *campo;
	};
	typedef strHeader header;




	return 1;
}
