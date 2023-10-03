#include <stdio.h>
#include <stdlib.h>


typedef struct libro{
    int id;
    int nombre;
    struct libro *sig;
}nodo;


void crear(nodo *p);
void mostrar(nodo *p);
nodo* insertar_principio(nodo *p);

int main(){
    nodo *prin;
    prin=(nodo *)malloc(sizeof(nodo));
    crear(prin);
    mostrar(prin);
    prin=insertar_principio(prin);
    mostrar(prin);
    return 0;    
}

void crear(nodo *p){
    printf("Ingrese el Id\n");
    scanf("%d",&p->id);
    if (p->id==0)
    {
        printf("Termino de cargar datos\n");
        p->sig=NULL;
    }
    else{
        p->sig=(nodo *)malloc(sizeof(nodo));
        crear(p->sig);
        
    }
    
}

void mostrar(nodo *p){
    if (p->sig==NULL)
    {
        printf("\nFin de lista\n");
    }
    else{
        printf("El elemento %d en el espacio %p\n",p->id,p);
        mostrar(p->sig);
    }
    

}

nodo* insertar_principio(nodo *p){
    nodo *a=(nodo *)malloc(sizeof(nodo));
    printf("Ingrese el Id para insertar al principio");
    scanf("%d",&a->id);
    a->sig=p;
    p=a;
    return p;

}