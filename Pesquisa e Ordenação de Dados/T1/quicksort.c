#include <stdio.h>
void troca(int *pos1, int *pos2){
	int aux = *pos1;
	*pos1 = *pos2;
	*pos2 = aux;
}
int particiona(int vector[], int inicio, int fim){
	int pv = fim;
	int i = inicio;
	int j = inicio;
	for(j=inicio;j<fim;j++){
		if(vector[j]<=vector[pv]){
			troca(&vector[i],&vector[j]);
			i++;
		}
	}
	if (vector[i]>vector[pv]){
		troca(&vector[i],&vector[pv]);
	}
	return pv;
}
void quickSort(int vector[], int inicio, int fim){
	if(fim>inicio){
		int pv = particiona(vector, inicio, fim);
		quickSort(vector, inicio, pv-1);
		quickSort(vector, pv+1, fim);
	}
}

int main(){
	int vector[] = {0,10,4,2,3,6,-2,8,11};
	int vectorLen = sizeof(vector)/sizeof(vector[0]);

	quickSort(vector,0,vectorLen-1);
	int i;
	for(i=0;i<vectorLen;i++){
		printf("%d, ",vector[i]);
	}
	return 0;
}
