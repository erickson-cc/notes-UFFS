/*******************

4. Faça um programa que peça 4 números inteiros. Em seguida, apresente quantos números informados são negativos e quantos são positivos (considere o 0 como positivo). Exemplos de execução:
	N1: 12		N1: -1
	N2: 4			N2: -20
	N3: -3		N3: -7
	N4: 5			N4: -11
	3 (+) e 1 (-)	0 (+) e 4 (-)

*******************/

#include <stdio.h>

int main()
{
    int i;
    int pos;
    int neg;
    int num;
    
    for(i=0;i<4;i++){
        printf("Informe um número\n");
        scanf("%d", &num);
        if(num>=0){pos++;}
        else{neg++;}
        }
    
    printf("A quantidade de números positivos foi %d\nA quantidade de números de negativos foi %d",pos,neg);

    return 0;
}
