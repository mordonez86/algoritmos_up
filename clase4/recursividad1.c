#include <stdio.h>
// dado un numero contar recursivamente cuantos numeros pares hay hasta llegar al cero 

int nros_pares(int numero,int contador){
    // caso base
    if(numero==0)
    return contador;

    //caso general
 if(numero %2 == 0){
    printf("%d",&numero);
    contador++;
 }
 return nros_pares(numero-1,contador);
}

int main(){
    int numero=10;
    int contador = 0;
    printf("%d", nros_pares(numero,contador));
}
