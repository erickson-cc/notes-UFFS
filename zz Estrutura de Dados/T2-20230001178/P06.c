/******************************************************************************
6. ⊙ Dada uma sequência de n números (um número menor ou igual à 0 finaliza a 
sequência), apresentar o porcentual de números informados que são maiores ou i
gual a 10 e menores ou igual a 20. Exemplo:  
Número: 5
Número: 6 
Número: 11 
Número: 21 
Número: 0 
% entre 10 e 20: 50% 


*******************************************************************************/

#include <stdio.h>

int main()
{
    int num=1; // número informado
    int count=-1; // contagem de números dados
    int pop=0; // números que estão dentro do escopo
    int perc; // percentual
    
    while(num>0){
        scanf("%d", &num);
        count++;
        if(num>=10 && num<=20){
            pop++;
        }
    }
    perc=100*pop/count;// O percentual não informa números após a vírgula pois
    //                // não é possível dividir 2 ints e armazernar em um float
    printf("%% entre 10 e 20: %d%%", perc);
    return 0;
}
