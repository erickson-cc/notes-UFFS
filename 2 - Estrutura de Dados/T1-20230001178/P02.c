/*********************************************************************************
2. Uma loja vende produtos à vista e a prazo (pagamento 30 dias depois da compra). À vista tem um desconto de 5% e a prazo um acréscimo de 10%. Faça um programa em C que peça o preço do produto e a forma de pagamento: 1 para à vista e 2 para a prazo. Depois apresente o preço final do produto. Exemplos de execução:
	Preço do produto: 120.00				Preço do produto: 200.00
	Forma de pagamento: 1				Forma de pagamento: 2
	Preço a vista: 114.00				Preço a prazo: 220.00
************************************************************************************/
#include <stdio.h>

int main()
{   
    //ENTRADA
    int val;
    int pag;
    float pre;
    
    printf("Informe o Preço do produto \n");
    scanf("%d", &val);
    
    printf("Informe o método de pagamento:\n1 - À Vista\n2 - À prazo\n");
    scanf("%d", &pag);
    
    //PROCESSAMENTO
    if(pag==1)
        {pre=val*0.95;}
    else{
        if(pag==2){pre=val*1.10;}
    else{printf("Rode o programa novamente e informe o método de pagamento correto.\n");}}
    
    //SAÍDA
    printf("Preço do produto:$%.2f", pre);
    
    return 0;
    }
