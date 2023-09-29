// Entregar la resolución de los siguientes ejercicios:

// Escribir un programa efectúe las siguientes operaciones:

// a) Declarar un arreglo de 20 posiciones de tipo int.

// b) Cargar sus elementos y mostrarlo en dos funciones (utilizando punteros).

// c) Realizar una función que cuente la cantidad de números pares que se cargaron en el arreglo y acumular los impares. 

// Mostrar los resultados ( recuerde que las funciones que calculan no imprimen).

// d) Recorrer con el puntero el arreglo, mostrando la dirección y el contenido de cada posición en forma prolija.

// Responda: 

// a) ¿Qué valor representa arreglo[2]?
// b) ¿Qué valor representa *(&arreglo[3+2])?
// c) ¿Qué valor representa *(arreglo+2)?
// d) ¿Qué valor representa arreglo[0]?
// e) ¿Qué valor representa *(arreglo-2)?


#include <stdio.h>

// prototipos de funciones
void cargar_arreglo(int *ptr);
void mostrar_arreglo(int *ptr);
void mostrar_arreglo_pretty(int *ptr);
void pares_impares(int *arr, int *pares, int *impares);

int main() {
    int arreglo[20];
    int pares = 0;
    int impares = 0;
    cargar_arreglo(arreglo);

    // Llamar a la función para mostrar el arreglo
    mostrar_arreglo(arreglo);

    pares_impares(arreglo, &pares, &impares);

    mostrar_arreglo_pretty(arreglo);

    printf("usted ingreso %d numeros pares\n", pares);
    printf("la suma de los numeros impares es: %d\n", impares);



    printf("\n---------------Respuestas--------------\n\n");
    printf("Arreglo[2] es igual a %d\n",arreglo[2]);
    printf("*(&arreglo[3+2]) es igual a %d\n",*(&arreglo[3+2]));
    printf("*(arreglo+2) es igual a %d\n",*(arreglo+2));
    printf("(arreglo[0]) es igual a %d\n",arreglo[0]);
    printf("*(arreglo-2) es igual a %d\n",*(arreglo-2));

    return 0;
}

// defino funcion de cargar
void cargar_arreglo(int *ptr) {
    printf("ingrese los 20 elementos del arreglo:\n");
    for (int i = 0; i < 20; i++) {
        scanf("%d", ptr + i);
    }
}

// defino funcion de mostrar
void mostrar_arreglo(int *ptr) {
    printf("\nlos elementos del arreglo son:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

// defino funcion de contar
void pares_impares(int *arr, int *pares, int *impares) {
    for (int i = 0; i < 20; i++) {
        if (arr[i] % 2 == 0) {
            (*pares)++;
        } else {
            (*impares) += arr[i];
        }
    }
}

void mostrar_arreglo_pretty(int *ptr){
    for (int i = 0; i < 20; i++){
        printf("\nel valor de la posicion %d de memoria es %d y el indice es %d\n",&ptr+i,*(ptr+i),i);
    }

}