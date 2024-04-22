/******************************************************************************
9. ⊘ Fazer um programa que simule um campeonato com 4 times (A, B, C e D). S
era pedido o nome do primeiro time com os gols marcados e o nome do segundo time
com os gols marcados. Este processo se repetirá até que seja informado um valor 
diferente de A, B, C ou D para o primeiro time. Ao final deverá ser apresentado 
o número de pontos de cada time e o campeão. Caso houver empate na primeira 
colocação informar que não houve campeão. Cálculo dos pontos: vitória 3 pontos,
empate 1 ponto e derrota 0 ponto. Exemplo: 

Time: A 
Gols: 2 
Time: B 
Gols: 1 
Time: C 
Gols: 2 
Time: A 
Gols: 4 
Time: X ← valor diferente de A, B, C ou D, então finaliza 
Campeão: A 
A: 6 pontos 
B: 0 pontos 
C: 0 pontos 
D: 0 pontos 


*******************************************************************************/
#include <stdio.h>

int main()
{
    /**PONTOS**/
    int A_pts=0;
    int B_pts=0;
    int C_pts=0;
    int D_pts=0;
    
    char time_x;// Time X que vai disputar contra o time Y
    char time_y;//
    
    int gols_x=0;
    int gols_y=0;
    for(;;){
        //resetando dentro do laço
        time_x=' ';
        time_y=' ';
        gols_x=0;
        gols_y=0;
        
        
        printf("Informe o nome do Primeiro Time: ");
        scanf("%c",&time_x);
        if(time_x!= 'A' && time_x!= 'B' && time_x!= 'C' && time_x!= 'D'){
            //RESULTADOS
            printf("Pontuação Total:\n A: %d pontos\nB: %d pontos\nC: %d pontos\nD: %d pontos",A_pts,B_pts,C_pts,D_pts);
            return 0;
            }
        printf("Informe o número de gols do Primeiro Time: ");
        scanf("%d",&gols_x);
        printf("Informe o nome do Segundo Time: ");
        scanf("%c",&time_y);
        printf("Informe o número de gols do Segundo Time: ");
        scanf("%d",&gols_y);
            
            if(gols_x>gols_y){
                if(time_x=='A'){
                    A_pts=A_pts + 3;
                }
                if(time_x='B'){
                    B_pts=B_pts + 3;
                }
                if(time_x='C'){
                    C_pts=C_pts + 3;
                }
                if(time_x='D'){
                    D_pts=D_pts + 3;
                }
                }
            if(gols_y>gols_x){
                if(time_y='A'){
                    A_pts=A_pts + 3;
                }
                if(time_y='B'){
                    B_pts=B_pts + 3;
                }
                if(time_y='C'){
                    C_pts=C_pts + 3;
                }
                if(time_y='D'){
                    D_pts=D_pts + 3;
                }
            }
            if(gols_x=gols_y){
                if(time_x='A'){
                    A_pts++;
                }
                if(time_x='B'){
                    B_pts++;
                }
                if(time_x='C'){
                    C_pts++;
                }
                if(time_x='D'){
                    D_pts++;
                }
                if(time_y='A'){
                    A_pts++;
                }
                if(time_y='B'){
                    B_pts++;
                }
                if(time_y='C'){
                    C_pts++;
                }
                if(time_y='D'){
                    D_pts++;
                }
            }

            }
    
    return 0;
}
