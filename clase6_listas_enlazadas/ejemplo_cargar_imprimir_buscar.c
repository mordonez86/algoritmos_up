#include <stdio.h>
#include <stdlib.h>

typedef struct libro
{
    int id;
    // char nombre[];

    struct libro *sig;

} nodo;

void crear(nodo *puntero)
{
    printf("ingrese id: ");
    scanf("%d", &puntero->id);
    if (puntero->id == 0)
    {
        puntero->sig = NULL;
    }
    else
    {
        puntero->sig = (nodo *)malloc(sizeof(nodo));
        crear(puntero->sig);
    }
};

void imprimir(nodo *puntero)
{
    if (puntero->sig == NULL)
    {
        printf("Fin\n");
    }
    else
    {
        printf("El id es %d\n", puntero->id);
        imprimir(puntero->sig);
    }
}

void buscar(nodo *puntero,int *search){
    if (puntero->sig==NULL)
    {
        printf("No se encontro coincidencia\n");
    }
    else if (puntero->id!=*search)
    {
        buscar(puntero->sig,search);
    }
    else{
        printf("Encontrado");
    };
}

int main()
{

    nodo *p;
    p = (nodo *)malloc(sizeof(nodo));
    int search_id;
    int *search=&search_id;
    crear(p);
    imprimir(p);
    printf("Ingrese el termino a buscar\n");
    scanf("%d",search);
    buscar(p,search);

}