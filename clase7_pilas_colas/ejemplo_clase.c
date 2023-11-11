#include <stdio.h>
#include <stdlib.h>

/* Contenido de la actividad

Se pide cargar una lista de números aleatorios.

Luego en base a los números ingresados en dicha lista, se le pide cargar dos listas más adicionales, en una de ellas solo se guardarán los números pares y en la otra, solo los impares. 

Una vez finalizada la carga de las tres listas, se deben mostrar de forma clara. Para luego eliminar los múltiplos de 5 de la lista de impares e insertar como primer elemento el 80 en la lista de pares.

Una ves finalizados, volver a mostrar.  */

typedef struct nodo
{
    int num;
    struct nodo *sig;
} nodo;

void cargar(nodo *puntero)
{
    printf("Ingrese el Nro: ");
    scanf("%d", &puntero->num);

    if (puntero->num == 0)
    {
        puntero->sig = NULL;
    }
    else
    {
        puntero->sig = (nodo *)malloc(sizeof(nodo));
        cargar(puntero->sig);
    }
};

// void dividir(nodo *puntero_lista_1,nodo *puntero_lista_2,nodo *puntero_lista_3){
// while (puntero_lista_1-> sig!= NULL)
// {
//     if(puntero_lista_1->num%2==0)
//     {
//         printf("numero_impar");
//         puntero_lista_2->num = puntero_lista_1->num;
//         puntero_lista_2->sig = (nodo *)malloc(sizeof(nodo));
//     }
//     else{
//         printf("numero par");
//         puntero_lista_3->num = puntero_lista_1->num;
//         puntero_lista_3->sig = (nodo *)malloc(sizeof(nodo));
//     }
//     puntero_lista_1=puntero_lista_1->sig;
// }}

//borrar 5 en lista impares
// sacarMultiplos(puntero_lista_2,5);
// insertarPrincipio(puntero_lista_3,80);
// };

// void sacarMultiplos(nodo *puntero_lista,int multiplo){
//     nodo *aux;

//     while (puntero_lista->sig !=NULL)
//     {
//         if(puntero_lista->num%multiplo==0){
//             aux = puntero_lista->sig->sig;
//             free(puntero_lista->sig);
//             puntero_lista->sig = aux;
//         }
//     }
// };

// insertarPrincipio(nodo * puntero_lista,int numero){
//     nodo *aux;
//     //insert 80 principio lista pares
//     aux = puntero_lista->num;
//     puntero_lista->num = numero;
//     puntero_lista->sig = aux;
// };


void mostrar(nodo *puntero)
{

    if (puntero->sig != NULL)
    {
        printf("Num %d\n", puntero->num);
    };
    mostrar(puntero->sig);
};

int main()
{
    nodo *puntero_lista_1;
    // nodo *puntero_lista_2;
    // nodo *puntero_lista_3;
    puntero_lista_1 = (nodo *)malloc(sizeof(nodo));
    // puntero_lista_2 = (nodo *)malloc(sizeof(nodo));
    // puntero_lista_3= (nodo *)malloc(sizeof(nodo));
    cargar(puntero_lista_1);
    mostrar(puntero_lista_1);
    // dividir(puntero_lista_1,puntero_lista_2,puntero_lista_3);
    return 0;
};