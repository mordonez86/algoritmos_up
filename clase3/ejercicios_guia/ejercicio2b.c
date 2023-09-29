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
            if (cant_letras == 1) {
                putchar(caracter); // Print the first letter of the word
            }
            caracter = getchar();
        }
        
        if (cant_letras > 2) {
            while (cant_letras > 0) {
                putchar(caracter); // Print the remaining letters of the word
                caracter = getchar();
                cant_letras--;
            }
        } else {
            while (caracter != '.' && caracter != ' ') {
                caracter = getchar(); // Skip the word with 2 or fewer letters
            }
        }
        
        if (caracter != '.') {
            putchar(' '); // Print a space between words
        }
    }
    
    return 0;
}
