#include <stdio.h>


int main(){
    //variables ingreso
    int sueldo , edad ;
    //variables sistema
    int edad_sueldo_10000;
    printf("ingrese el sueldo");
    scanf("%i",&sueldo);
    printf("ingrese la edad");
    scanf("%i",&edad);
    while (edad!=0&&sueldo!=0)
    {
        if(sueldo>10000){
            edad_sueldo_10000+=edad;
        }
    }
    printf("la edad de los que tienen sueldo mayor a 100000 es ");

}