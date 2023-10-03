#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num;
    struct lista *sig;
} nodo;

void cargar(nodo *p);
void mostrar(nodo *p);
void insertar(nodo *p);
nodo* insertarCabeza(nodo *p);

int main()
{
    nodo *prin;
    prin = (nodo *)malloc(sizeof(nodo));
    cargar(prin);
    // mostrar(prin);
    insertar(prin);
    mostrar(prin);
    prin=insertarCabeza(prin);
    mostrar(prin);
    return 0;
}

void cargar(nodo *p)
{
    printf("Ingrese el numero: \n");
    scanf("%d", &p->num);
    if (p->num == -2)
    {
        printf("Carga Finalizada\n");
        p->sig = NULL;
    }
    else
    {
        p->sig = (nodo *)malloc(sizeof(nodo));
        cargar(p->sig);
    }
};

void mostrar(nodo *p)
{
    if (p->sig == NULL)
    {
        printf("---FIN DE LISTA---\n");
    }
    else
    {
        printf("El valor es %d\n", p->num);
        mostrar(p->sig);
    }
};

void insertar(nodo *p){
    if (p!=NULL &&p->sig!=NULL)
    {
        if (p->num%2==0)
        {
            nodo *aux;
            aux=(nodo *)malloc(sizeof(nodo));
            aux->num=321;
            aux->sig=p->sig;
            p->sig=aux;
            insertar(p->sig->sig);
        }
        else{
            insertar(p->sig);
        }  


    }
    
}

nodo* insertarCabeza(nodo *p){
    nodo *aux=(nodo *)malloc(sizeof(nodo));
    aux->num= 495;
    aux->sig=p;
    p=aux;
    return p;
}