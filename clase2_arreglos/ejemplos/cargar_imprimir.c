#include <stdio.h>


// forma basica de leer por consola los valores e ingresarlos en un array tanto de forma manual en el main , como ejecutando dos funciones


int cargar(int array[5]){
    
    printf("Cargando\n");
    for(int i = 0; i < 5 ; i++){
        printf("ingrese para la posicion%d: ",i);
        scanf("%d", &array[i]);
    };
    return array;
}


//prototipo de funcion imprimir
void imprimir(int array[5]);

int main()
{
    int array[5];
    cargar(array);
    imprimir(array);
    return 0;
}


// definicion funcion imprimir
void imprimir(int array[5]){
    printf("\n\nImprimiendo\n");
    for(int i = 0; i < 5; i++){
        printf("Your Input Was: %d\n",array[i]);
    };
}