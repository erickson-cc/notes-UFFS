#include <stdio.h>
void setNum(int *num, int new){
	*num = new;
}
int main(){
	int num = 0;
	
	printf("%d\n",num);
	setNum(&num,5);
	printf("%d\n",num);
	return 1;
}
