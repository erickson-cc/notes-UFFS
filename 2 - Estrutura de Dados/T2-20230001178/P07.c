/******************************************************************************
7. ⊙ Faça um programa que peça o salário e o número de filhos dos habitantes de 
uma região. Quando o salário informado for menor que zero, as entradas são final
izadas e serão apresentadas as médias salarial e de filhos informados. Exemplo: 

Salário: 1500 
Filhos: 2 
Salário: 3245 
Filhos: 2 
Salário: -1 
Média salários: 2372.5 
Média filhos: 2.0 


*******************************************************************************/

#include <stdio.h>

int main()
{
    float sal, sal_sum=0,sal_med; //Salário Atual//Soma de Salários//Média de Salários//
    float fil, fil_sum=0, fil_med; //Filhos Atual//Soma de Filhos//Média de Filhos//
    int count=0;//Contador do laço

    
    while(sal>=0){
        printf("Salário: ");
        scanf("%f", &sal);
        if(sal>=0){//Colocando essa condicional para encerrar o laço após o scanf
            count++;
            sal_sum=sal_sum+sal;
            printf("Filhos: ");
            scanf("%f", &fil);
            fil_sum=fil_sum+fil;
        }
    }
    /* Calculando as Médias */
    sal_med = sal_sum/count;
    fil_med = fil_sum/count;
    
    printf("Média Salários: %.2f\n", sal_med);
    printf("Média Filhos: %.1f", fil_med);
    
    return 0
}
