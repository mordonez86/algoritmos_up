//2. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar el texto con un blanco y eliminando las palabras de 1 letra.

#include <stdio.h>

int main() {
    char caracter;
    int count = 0;
    int cant_letras = 0;

    printf("Ingrese la Frase\n");
    caracter = getchar();

    // primero recorro y verifico que no sea un punto
    while (caracter != '.') {
        // luego recorro y verifico que no sea un espacio
        while (caracter == ' ') {
            cant_letras = 0; // Reset letter count for each new word
            caracter = getchar();
        }
        
        while (caracter != '.' && caracter != ' ') {
            cant_letras += 1;
            if (cant_letras > 2) {
            putchar(caracter); // Print only the first letter of the word
            caracter = getchar();
            //putchar(caracter);
            }
        }
            printf(" ");
    }
    
    return 0;
}