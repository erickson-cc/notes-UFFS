/******************************************************************************
8. ⊙ Antonio tem 1,50m e cresce 2cm por ano. Carlos tem 1,10m e cresce 3cm por 
ano. Fazer um programa que calcule quantos anos seriam necessários para que 
Carlos tivesse a mesma altura que Antonio. Supondo que os dois crescem todos os anos. 
*******************************************************************************/
#include <stdio.h>

int main()
{// ant = Antonio Car = Carlos
// h = altura, a = crescimento anual
    int ant_h=150;
    int car_h=110;
    int ant_a=2;
    int car_a=3;
    int yrs=1;// Anos
    
    for(yrs;car_h<ant_h;yrs++){
        ant_h = ant_h + ant_a;
        car_h = car_h + car_a;
        printf("Após %d anos a altura de Carlos é %d cm e a altura de Antonio é %d cm.\n",yrs,car_h,ant_h);
    }
    printf("\nO tempo necessário para que a altura de Carlos e Antonio sejam iguais é %d anos.",yrs-1);// subtrair dos anos pois ele é somado ao final da última iteração
    return 0;
}
