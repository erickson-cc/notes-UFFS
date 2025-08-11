/******************************************************************************
10. ⊘ Um professor gostaria de ter um programa para calcular a média final de seus
alunos. Para isso, ele informa a matrícula e as 5 notas que o alunos teve durante 
o semestre. Após informar as 5 notas, o programa imprime a matrícula do aluno e a
média que obteve (média aritmética simples). Quando o professor digitar 0 o programa
finaliza e apresenta a média geral da turma. Proibido colocar 5 scanf para pedir as 
notas. Exemplo: 

Matrícula: 22010 
Nota 1: 4 
Nota 2: 6 
Nota 3: 6 
Nota 4: 6 
Nota 5: 8 
Aluno: 22010  Média: 6.0
Matrícula: 0 
Média geral da turma: 6.0

*******************************************************************************/
#include <stdio.h>

int main()
{
    int mat;
    float nota;//Tem que ser float para dar a média em float
    int count=0;//contagem de alunos
    float med_aluno;
    float sum_aluno;
    float sum_turma=0;
    float med_turma;
    int i=1;//i = nota individual
    
    for(;;){//feito um laço infinito que é interrompido com uma condicional
        sum_aluno = 0;
        printf("Matrícula: ");
        scanf("%d",&mat);
        /*****Última parte do Código*****/
        if(mat==0){
            med_turma = sum_turma/(count*5);//multiplicar por 5 que é a qt de notas
            printf("Média geral da turma: %.1f",med_turma);
            return 0;
        }
        /*******************************/
        for(i=1;i<=5;i++){//Pedir notas do aluno atual
            printf("Nota %d:", i);
            scanf("%f",&nota);
            sum_aluno = sum_aluno + nota;
            med_aluno = sum_aluno/i;
        }
        count++;
        sum_turma = sum_turma + sum_aluno;
        printf("Aluno: %d Média: %.1f\n", mat, med_aluno);
    }
    return 0;
}
