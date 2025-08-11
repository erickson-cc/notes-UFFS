/******************************************************************************

5. Você vai fazer um programa para classificar os competidores segundo as suas posições. Foram criadas 5 classes: Top 5 (1-5), Top 10 (6-10), Top 20 (11-20), Top 30 (21-30) e Top 100 (outras posições). Faça um programa que peça a posição do competidor e indique a classe do mesmo. Exemplos de execução:
	Posição: 12		Posição: 5		Posição: 34
	Top 20		Top 5			Top 100



*******************************************************************************/

#include <stdio.h>

int main()
{
    int pos;
    int top;
    
    printf("Informe a Posição do Competidor\n");
    scanf("%d", &pos);
    
    if(pos<=100){
        if(pos>0){
            top=5; // Igualando
            if(pos>5){top+=5;}// Adicionando
            if(pos>10){top+=10;}// "" "" ""
            if(pos>20){top+=10;}// "" "" ""
            if(pos>30){top=100;}// Igualando
        
        printf("O Competidor está na classe: Top %d", top);    
        }
        
    }

    return 0;
}
