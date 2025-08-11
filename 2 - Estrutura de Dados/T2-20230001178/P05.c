/******************************************************************************

5. ⊘ Faça um programa para calcular o fatorial de um número dado. O fatorial d
e um número n é n × (n − 1) × (n − 2) × . . . × 1, por definição o fatorial d
0 e 1 é 1. Por exemplo, o fatorial de 5 é 120, ou seja, 5 × 4 × 3 × 2 × 1 (perc
eba que não é necessário fazer a última multiplicação já que 1 é o elemento neu
tro da multiplicação). 

*******************************************************************************/

#include <stdio.h>

int main()
{
    int num;//Número solicitado
    int i;//variável do loop
    int res=1;// num!
    
    printf("Informe o Número: ");
    scanf("%d", &num);
    
    for(i=1;i<=num;i++){
        res= res*i;
    }
    if(num>=0){//Não existe fatorial negativo
    printf("%d! = %d",num, res);
    }

    return 0;
}
