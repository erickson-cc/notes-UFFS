/******************************************************************************
3. ⊙ Faça um programa que peça uma valor e imprima a soma de todos os números 
de 1 até o valor informado. Por exemplo, se o valor informado for 6, o resultado
será 21, ou seja, 1 + 2 + 3 + 4 + 5 + 6. 
 

*******************************************************************************/

#include <stdio.h>

int main()
{
    int num;//número informado
    int i;//usado no loop
    int res;//resposta
    
    printf("Informe o número: ");    
    scanf("%d", &num);
    
    res = 0;
    
    for(i=1;i<=num;i++){
        res=res+i;
        if(i==num){printf("%d=%d", i,res);}//final do loop
        else{printf("%d+", i);}
    }
    
    return 0;
}
