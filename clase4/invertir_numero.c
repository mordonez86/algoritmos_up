#include <stdio.h>

//dado un numero debo retornar en formato int el inverso
int invertir(int numero,int invertido){
    if (numero < 10)
    return invertido + numero ;
    invertido+=numero % 10;
    invertido =invertido * 10;
    return invertir(numero/10,invertido);    
}



int main()
{
    /* code */
    int numero = 321;
    int invertido  ;
    int resultado ;
    resultado=invertir(numero,invertido);
    printf("%d", &resultado);
    return 0;
}
