// . Escribir un programa efectúe las siguientes operaciones:
// a) Declarar un arreglo de quince posiciones de tipo float. Cargar sus elementos y
// mostrarlo.
// b) Declarar un puntero a float.
// c) Asignar al puntero la dirección del arreglo.
// d) Recorrer con el puntero el arreglo, mostrando la dirección y el contenido de cada
// posición.
#include <stdio.h>

void mostrar(float *ptr)
{
    for (int i = 0; i < 15; i++)
    {
        printf("el valor %.2f esta en la direccion %p\n", *(ptr+i), ptr+i);
    }
}

int main()
{
    float array[15] = {1.0, 2.5, 3.3, 4.7, 5.2, 6.8, 7.1, 8.9, 9.4, 10.6, 11.2, 12.3, 13.5, 14.7, 15.0};
    float *ptr = array;
    mostrar(ptr);
}