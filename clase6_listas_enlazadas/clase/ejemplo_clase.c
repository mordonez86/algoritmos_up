#include <stdio.h>
#include <stdlib.h>


// aca se crean dos punteros ,uno interno que es parte del tpo de datos y lo que hace es apuntar al proximo nodo
// el segundo puntero es el que apunta solamente al primer espacio en memoria de la estructura

// defino el tipo de dato 
typedef struct lista{
    int numero;
    struct lista *sig;    
}nodo;

//prototipo de funciones
//crear recibe el puntero de tipo nodo que declaramos en main
void crear(nodo *puntero);
void mostrar();


int main(){
    // defino el puntero con el mismo tipo de dato definido mas arriba (nodo)
    nodo *p;
    // aca es cuando reservamos el espacio en memoria , usando sizeof para saber el tamaño del tipo de nodo como maximo 
    // en donde dice (nodo *) lo que estoy haciendo es castear el tamaño de nodo a un tipo de dato 
    // este tipo de estructura es utilizada porque me permite ir llenando espacios en memoria sin la necesidad de que tengan que ser contiguos
    // aca la asignacion del puntero es siempre la misma , estudiar que significa cada parte y tenerlo bien claro 
    p=(nodo*)malloc(sizeof(nodo));
    crear(p);
    mostrar(p);

    return 0;

}

//definicion de funcion crear
void crear(nodo *puntero){
    //con recursividad cargo el nodo con numeros enteros
    //caso base
    printf("Ingrese un numero");
    scanf("%d",&puntero->numero);
    if(puntero->numero==0){
        puntero->sig=NULL;
    }
    else{
        // caso general , sigo pidiendo datos hasta que el dato sea 0
        puntero->sig=(nodo *)malloc(sizeof(nodo));
        crear(puntero->sig);
    }
}

//definicion de funcion mostrar
void mostrar(nodo* puntero) {
    if (puntero == NULL) {
        printf("NULL\n");
        return 0;
    }

    printf("%d -> ", puntero->numero);
    mostrar(puntero->sig);
}