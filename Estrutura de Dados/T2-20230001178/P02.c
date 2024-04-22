/******************************************************************************
2. ⊙ Faça um programa que simule a multiplicação por meio de adições. Para tal s
erãoo pedidos os dois operandos. Por exemplo se for informado 3 e 4, deverá ser 
calculado, usando a soma, 3∗4, ou seja, 12. Este cálculo é feito somando o prime
iro valor informado por ele mesmo o número de vezes representada pelo segundo nú
mero. Nesse exemplo, o três seria somado quatro vezes: 3+3+3+3, resultando 12. 

*******************************************************************************/

#include <stdio.h>

int main()
{
    int val;//value ou número 1
    int mul;//multiplicador ou número 2
    int i;//loop
    int res;//result
    
    printf("Informe o primeiro número: ");    
    scanf("%d", &val);
    
    printf("Informe o segundo número: ");
    scanf("%d", &mul);

    res = 0;

    for(i=1;i<=mul;i++){
        res=res+val;// vai adicionando com o res que restou do laço anterior
        if(i==mul){printf("%d=%d", val,res);}//fim do loop
        else{printf("%d+", val);}
    }
    
    return 0;
}
