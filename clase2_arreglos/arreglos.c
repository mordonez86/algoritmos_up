// por el momento los arreglos los vamos a definir en main
// todo siempre es una funcion

#include <stdio.h>

int cargar(int vec[]){
    for (int i=0;i<5;i++){
        vec[i]=i;
    }    
}
int imprimir(int vec[]){
    for (int i=0;i<5;i++){
    printf("%d\n",i);
    }    
}

int main() {
    int vec[5];
    printf("creo vector\n");
    cargar(vec);
    imprimir(vec);

}