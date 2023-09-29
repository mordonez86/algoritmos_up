#include <stdio.h>

// cuando encuentra MB seguidas lo reemplaza por asteriscos 
int main()
{
    
    int caracter;

    printf("Ingrese la Frase\n");
    caracter=getchar();        

    while(caracter!='.'){
       caracter=getchar();
       scanf("%s", caracter);       
        }
    printf("while");    
    return 0;
}