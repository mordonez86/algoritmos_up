#include <stdio.h>

// existen dos metodos de trabajar con strings  una usando la libreria string.h para trabajar el string de caracteres como un conjunto , pero si necesito comparar letra por letra
// los dos strings , conviene utilizar la segunda forma en este archivo esta la segunda 
int main()
{
    // en este caso se utiliza el metodo getchar este metodo va a recordar solamente 1 char recorriendolo de a uno por lo tanto necesitamos utilizar un while para ir recorriendo 
    int caracter;
    int count=0;
    int counta=0;

    printf("Ingrese la Frase\n");
    caracter=getchar();        

    while(caracter!='.'){
        while (caracter==' ')
        {
            caracter=getchar();
            if (caracter=='a')
            {
                counta +=1;
            }
            
        }
            while (caracter!='.' && caracter!=' ')
            {
            caracter=getchar();
            if( caracter==' '|| caracter=='.'){
                count +=1;
                }
            }            
        }
    printf("Ingreso %d palabras", count);
    printf("Ingreso %d palabras con A",counta);
    return 0;
}
