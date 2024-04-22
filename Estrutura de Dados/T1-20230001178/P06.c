/******************************************************************************

6. Sabendo que as faixas etárias para votação são: 18 a 70 anos voto obrigatório; 16, 17 e acima de 70 anos voto facultativo; outras idades (ou seja, menor que 16 anos) não pode votar, crie um programa que processa essa verificação. Exemplos de execução:

	Idade: 20			Idade: 17			Idade: 12
	Voto obrigatório		Voto facultativo		Não pode votar



*******************************************************************************/

#include <stdio.h>

int main()
{
    int idd;
    int stage;//1-não pode 2-facultativo 3- obrigatório
    
    printf("Informe a idade do eleitor\n");
    scanf("%d", &idd);
    
    if(idd>=0){
        stage=1; 
        if(idd>=16){stage+=1;}
        if(idd>=18){stage+=1;}
        if(idd>70){stage-=1;}
        
        if(stage==1){
            printf("Não pode Votar");
        }
        if(stage==2){
            printf("Voto Facultativo");
        }
        if(stage==3){
            printf("Voto Obrigatório");
        }
    }
        
    

    return 0;
}
