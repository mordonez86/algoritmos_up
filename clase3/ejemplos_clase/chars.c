#include <stdio.h>
#include <string.h>

// existen dos metodos de trabajar con strings  una usando la libreria string.h para trabajar el string de caracteres como un conjunto , pero si necesito comparar letra por letra
// los dos strings , conviene utilizar la segunda forma en este archivo esta la primera 
int main()
{
    char nombre[30] , nombre2[30];
    char a;
    printf("Ingrese el caracter: ");
    scanf("%c",& a);
    printf("Usted Ingreso %c\n",&a);
    //las cadenas de caracteres (strings) no llevan ampersand cuando se lo llama en el scan ni en el print
    printf("Ingrese nombre: ");
    scanf("%s",nombre);
    printf("El nombre es %s",nombre);

    // para copiar un string se usa una libreria especial llamada string y el metodo stringCopy
    // para comparar strings se utiliza el equivalente en codigo asci y se comparan las dos cadenas usando string compare tomando en cuenta el lugar que se encuentra 

    return 0;
}
