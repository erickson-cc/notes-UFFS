/***********************************************************************************
1. Faça um programa que peça o número de horas trabalhadas e o valor da hora de um determinado funcionário. Em seguida, calcule o salário do funcionário. Caso o funcionário tenha trabalhado mais de 200 horas, o salário final é acrescido de 5%. Exemplos de execução:
	Horas trabalhadas: 120				Horas trabalhadas: 210
	Valor da hora: 100,00				Valor da hora: 50.00
	Salário: 12000.00					Salário: 11025.00
***********************************************************************************/

#include <stdio.h>

int main()
{   
    int h;
    int n;
    int sal;
    
    printf("Digite o número de horas trabalhadas\n");
    scanf("%d", &h);

    printf("Digite o valor da hora trabalhada\n");
    scanf("%d", &n);
    
    if(h<=200) {sal = h*n;}
    else {sal = h*n*1.05;}
    
    printf("O salário desse funcionário é: $%d", sal);
    
    return 0;
}
