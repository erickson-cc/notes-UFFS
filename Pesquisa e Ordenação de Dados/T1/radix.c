#include <stdio.h>
void counting(int *vector, int size, int pos){
	int aux[size];
	int count[10];
	int digit;
	int i;
	for(i=0;i<10;i++){
		count[i]=0;
	}

	for(i=0;i<size;i++){
		digit = (vector[i]/pos)%10;
		count[digit]++;
	}
	for(i=1;i<10;i++){
		count[i] = count[i]+count[i-1];
	}
	for(i=size-1;i>=0;i--){
		digit = (vector[i]/pos)%10;
			count[digit]--;
			aux[count[digit]]=vector[i];
	}
	for(i=0;i<size;i++){
		vector[i] = aux[i];
	}
}
int searchMaior(int *vector, int vectorLen){
	int maior;
	int i;
	maior = 0;

	for(i=0;i<vectorLen;i++){
		if(vector[i]>maior){
			maior = vector[i];
		}
	}
	return maior;
}
void radixSort(int *vector, int vectorLen){
	int pos;
	int max;
	max = searchMaior(vector, vectorLen);
	for(pos=1;max/pos>0;pos*=10){
		counting(vector,vectorLen,pos);
	}
}
int main(){
	int vector[] = {0,10,4,2,3,6,15,3,11,8};
	int vectorLen = sizeof(vector)/sizeof(vector[0]);
	radixSort(vector,vectorLen);
	int i;
	for(i=0;i<vectorLen;i++){
		printf("%d, ",vector[i]);
	}
	return 0;
}
