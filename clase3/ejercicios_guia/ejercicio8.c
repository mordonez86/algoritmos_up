#include <stdio.h>
// Ingresar un texto carácter a carácter terminado en PUNTO. 
// Contar cuantaspalabras empiezan con la anteúltima letra de la palabra anterior. 
// En palabras de 1 sola letra deberá tomar esta única letra como anteúltima.


int main(){
// en este caso se utiliza el metodo getchar este metodo va a recordar solamente 1 char recorriendolo de a uno por lo tanto necesitamos utilizar un while para ir recorriendo 
    char caracter;
    char caracter_anterior;
    int count=0;

    printf("Ingrese la Frase\n");
    caracter=getchar();        

// primero recorro  y verifico que no sea un punto
    while(caracter!='.'){
        // luego recorro y verifico que no sea un espacio
        while (caracter==' ')
        {
            
            caracter=getchar();
            
        }
            while (caracter!='.' && caracter!=' ')
            {

            caracter=getchar();
            caracter_anterior=caracter;
            if( caracter==' '|| caracter=='.'){
                count +=1;
                }
            }            
        }
    printf("\nIngreso %d palabras", count);

    return 0;
}