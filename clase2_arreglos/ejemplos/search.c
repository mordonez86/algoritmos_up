#include <stdio.h>


char crear_array(char array[10]){
    char palabras[10]; // Declarar un arreglo de cadenas de caracteres

    // Asignar valores (palabras en español) al arreglo
    palabras[0] = "Enciclopedia";
    palabras[1] = "Maravillosamente";
    palabras[2] = "Extraordinario";
    palabras[3] = "Inexplicable";
    palabras[4] = "Melancolía";
    palabras[5] = "Simultáneamente";
    palabras[6] = "Desafortunadamente";
    palabras[7] = "Espectacular";
    palabras[8] = "Ubicación";
    palabras[9] = "Valentía";
    return palabras;

}


int main()
{
    char array[10]; 
    crear_array(array);

    for(int i = 0;i < 10; i++){
        printf("la palabra en el indice %d es %s\n",i+1,array[i]);
    };
}
