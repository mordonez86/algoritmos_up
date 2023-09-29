#include <stdio.h>

int main() {
    char caracter;
    char caracter_anterior = ' ';
    char anteultima_letra = ' '; 
    int numero_letra = 0 ;
    int count = 0;

    printf("Ingrese la Frase:\n");
    caracter = getchar();

    while (caracter != '.') {
        while (caracter == ' ') {
            caracter = getchar();
            numero_letra = 0 ;

        }

        while (caracter != '.' && caracter != ' ') {
            numero_letra += 1;
            if (anteultima_letra != ' ' && numero_letra == 1) {                
                if (caracter == anteultima_letra ) {
                    count += 1;
                }
            }
            
            // penultima
            anteultima_letra = caracter_anterior;

            // anterior
            caracter_anterior = caracter;

            // leo nuevamente el char
            caracter = getchar();
        }


    }

    printf("\nIngreso %d palabras\n", count);

    return 0;
}
