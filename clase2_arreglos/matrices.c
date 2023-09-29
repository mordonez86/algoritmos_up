#include <stdio.h>


//funcion que genera matriz , es void porque no devuelve nada , tiene una variable para contar (num) y es el valor 
//de relleno dentr de la matriz recibe como parametro la matriz generada desde main
//Esta funcion esta llamada por definicion , se define antes de la funcion main en su codigo completo
void genero_matriz(int mat[3][3]) {
    int num = 0;
    printf("matrices\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] = num;
            num += 1;
        }
    }
}

//funcion que recibe una matriz y la imprime por pantalla
//Esta funcion esta llamada por definicion , se define antes de la funcion main en su codigo completo
void imprimo_matriz(int mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("[%d]",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// esta funcion transpone la matriz (filas a columnas , columnas a filas , recibe dos parametros , el primero es
// la matriz original , el otro es una matriz vacia para rellenar con los resultados iterados de la matriz original)
// Esta funcion esta llamada por prototipo , se declara al principio solo el nombre y los parametros 
// y luego se define debajo del main
void transpongo_matriz(int mat[3][3],int transpuesta[3][3]);

int main() {
    //variables
    int matriz[3][3];
    int transpuesta[3][3];
    //llamadas a las funciones
    genero_matriz(matriz);
    imprimo_matriz(matriz);
    transpongo_matriz(matriz,transpuesta);
    imprimo_matriz(transpuesta);
    return 0;
}

// esta funcion transpone la matriz (filas a columnas , columnas a filas , recibe dos parametros , el primero es
// la matriz original , el otro es una matriz vacia para rellenar con los resultados iterados de la matriz original)
void transpongo_matriz(int mat[3][3],int transpuesta[3][3]) {    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transpuesta[i][j]=mat[j][i];
        }
        
    }
}