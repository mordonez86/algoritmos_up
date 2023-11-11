#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

typedef struct Nodo Nodo;

//funcionq crea
Nodo* crear(int valor) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = NULL;
    return nuevo_nodo;
}

// insertar el nro al principio
void insertar_principio(Nodo** cabeza, int valor) {
    Nodo* nuevo = crear(valor);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}


// mostrar
void imprimir(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
    printf("%d ", actual->dato);
    actual = actual->siguiente;
    }
    printf("\n");
}

void eliminar_mult5(Nodo** cabeza) {
    Nodo* actual = *cabeza;
    Nodo* previo = NULL;

    while (actual != NULL) {
        if (actual->dato % 5 == 0) {
            Nodo* temp = actual;
            if (previo != NULL) {
                previo->siguiente = actual->siguiente;
                actual = actual->siguiente;
            } else {
                *cabeza = actual->siguiente;
                actual = *cabeza;
            }
            free(temp);
        } else {
            previo = actual;
            actual = actual->siguiente;
        }
    }
}

int main() {
    Nodo* lista = NULL;
    Nodo* pares = NULL;
    Nodo* impares = NULL;
    
    int n;
    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &n);
    
    printf("Ingrese %d numeros aleatorios:\n", n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        insertar_principio(&lista, num);
    }
    
    Nodo* actual = lista;
    while (actual != NULL) {
        if (actual->dato % 2 == 0) {
            insertar_principio(&pares, actual->dato);
        } else {
            insertar_principio(&impares, actual->dato);
        }
        actual = actual->siguiente;
    }

    printf("\nLista de numeros ingresados:\n");
    imprimir(lista);
    
    printf("\nLista de numeros pares:\n");
    imprimir(pares);
    
    printf("\nLista de numeros impares:\n");
    imprimir(impares);
    
    eliminar_mult5(&impares);
    insertar_principio(&pares, 80);

    printf("\nLista de numeros pares (con 80 al principio):\n");
    imprimir(pares);
    
    printf("\nLista de numeros impares (sin multiplos de 5):\n");
    imprimir(impares);
    
    return 0;
}