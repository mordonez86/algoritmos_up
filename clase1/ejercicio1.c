#include <stdio.h>

int main(){
    float peso = 0 ;
    float altura = 0;
    float imc = 0 ; 
    int salir = 0;

    while (salir!=1)
    {
        printf("ingrese el peso ");
        scanf("%f",&peso);
        printf("ingrese la altura ");
        scanf("%f",&altura);
        imc = peso / (altura * altura);
        printf("El IMC es : %f\n",imc);
        printf("desea salir??\n1:SI\n2:NO");
        scanf("%d",&salir);
    }
    return 0;
    

}