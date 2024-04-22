/*******************
3. Faça um programa que calcule a duração de um evento qualquer. Para tal, o programa pede a hora de início e hora de fim (sem os minutos), as horas serão informadas de 0 a 23. Perceba que um evento pode começar em um dia e acabar em outro. Os eventos nunca terão duração de mais de 24 horas. Exemplos de execução:
	Início: 12			Início: 10			Início: 21
	Fim: 4			Fim: 15			Fim: 6
	Duração: 16 horas		Duração: 5 horas		Duração: 9 horas
*************************/

#include <stdio.h>

int main()
{   
    //ENTRADA
    int ini;
    int fim;
    int dur;
    
    printf("Informe o início do evento\n");
    scanf("%d", &ini);
    
    printf("Informe o término do evento\n");
    scanf("%d", &fim);
    
    //PROCESSAMENTO
    if(fim>ini){
        dur = fim-ini;
        }
    else{
        dur = fim-ini+24;
        }
    
    //SAÍDA
    if(fim <= 23){///////////////////////
        if(fim >= 0){/////////CONDIÇÕES//
            if(ini <= 23){///////////////
                if(ini >= 0){////////////
            
    printf("Duração do evento: %d horas.\n", dur); }}}}
        else{
    printf("As Horas devem ser entre 0 e 23");
        }
                    
    
    return 0;
    }
