#include <stdio.h>

int main()
{
    int arreglo1[5];
    int arreglo2[5];
    int contador=1;
    int resultado[5];

    int j=0;
    for(int i =0;i<10;i++){
        if (contador<=5)
        {
            arreglo1[i]=contador;
        }
        else{
            arreglo2[j]=contador;
            j++;
        }
    contador++;
    }

    for(int i=0;i<5;i++){
        resultado[i]=arreglo1[i]+arreglo2[i];
    };

        for(int i=0;i<5;i++){
        printf("Resultado %d\n",resultado[i]);
    }

    return 0;
}
