#include <stdio.h>
void ShowDD(int *v, int vLen){
	int i, j, isDom; //1
	for(i=0;i<vLen;i++){ //vLen
		isDom = 1; //vLen
		for(j=i+1;j<vLen;j++){ //vLen*(vLen-i)
			if(v[i]<=v[j]){
				isDom=0;
			}
		}
		if(isDom==1){
			printf("%d ",v[i]);
		}
	}
}
void ShowDD_linear(int *v, int vLen){
	int i, bigLeft=v[vLen];
	for(i=vLen;i>0;i--){
		if(v[i]>=bigLeft){
			printf("%d ",v[i]);
			bigLeft=v[i];
		}
	}
}
int main(){
	int vector[6] = {5,3,7,2,9,1};

	ShowDD(vector,6);
	printf("=================\n");
	ShowDD_linear(vector,6);

	return 0;
}

