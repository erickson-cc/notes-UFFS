/******************************************************************************

1. • Faça um programa que peça um número e imprima os números de 1 até o número
informado. Sendo que, quando chegar na metade da impressão, mostrar a mensagem
Metade (a metade não precisa ser exata). Exemplos: 
Número: 6					Número: 7		ou	Número: 7
1 						1				1
2 						2				2
3 						3				3
Metade 						4				Metade
4 						Metade			4	
5 						5				5
6 						6				6
							7				7
*******************************************************************************/

#include <stdio.h>

int main()
{
    int num;//número desejado
    int i;
    
    printf("Número: ");
    scanf("%d",&num);
    for(i=1;i<=num/2;i++){//primeira parte
        printf("%d\n",i);
    }
    printf("Metade\n");
    for(i;i<=num;i++){//segunda parte
        printf("%d\n",i);
    }
    return 0;
}
