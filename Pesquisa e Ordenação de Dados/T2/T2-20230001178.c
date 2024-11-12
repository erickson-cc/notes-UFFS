#include <stdio.h>
//#include <string.h>
#include <stdlib.h>
struct tlist{
	int valor;
	struct tlist *next;
};
typedef struct tlist hashnode;
/* uma função hash é formada por duas partes
 *	Criação do valor de hash(transformar K em um numero inteiro ainda que não esteja em [0,M-1]
 *	Compressão: transforma o numero em um valor que esteja em [0,M-1]
 */

void initHashTable(hashnode *hashTable, int M){
	int i;
	for(i=0;i<M;i++){
		hashTable[i] = NULL;
	}
}
int main(){
	int M = 23; //Tamanho da tabela Hash
	int k = 23; //Chaves
	hashnode hashTable[M];
	initHashTable(&hashTable,M);
	int kmodm = k % M;
	printf("%d",kmodm);	
	return 0;
}
