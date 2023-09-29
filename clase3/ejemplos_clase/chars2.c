#include <stdio.h>

// existen dos metodos de trabajar con strings  una usando la libreria string.h para trabajar el string de caracteres como un conjunto , pero si necesito comparar letra por letra
// los dos strings , conviene utilizar la segunda forma en este archivo esta la segunda 
int main()
{
    // en este caso se utiliza el metodo getchar este metodo va a recordar solamente 1 char recorriendolo de a uno por lo tanto necesitamos utilizar un while para ir recorriendo 
    int caracter;
    printf("Ingrese la Frase");
    caracter=getchar(); 
       
    while(caracter!='.'){
        putchar(caracter);
        caracter=getchar();
    }
    return 0;
}
