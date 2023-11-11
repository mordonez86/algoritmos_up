#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    int dni;
    char nombre[20];
    float saldo;
    struct lista *sig;
}nodo;



void cargar(nodo *p);
void mostrar(nodo *p);
void pasar(nodo *p,nodo *n);




int main()
{
    nodo *puntero=(nodo *)malloc(sizeof(nodo));
    nodo *negativos=(nodo *)malloc(sizeof(nodo));
    int opcion;

    printf("Ingrese que desea hacer: \n");
    scanf("%d",&opcion);


    while (opcion!=0)
    {
        if (opcion==1)
        {
            cargar(puntero);
        }
        else if (opcion==2)
        {
            printf("Los normales son:\n");
            mostrar(puntero);
            printf("Los filtrados son:\n");
            mostrar(negativos);
        }
        else if (opcion==3)
        {
            pasar(puntero,negativos);
        }
        printf("Ingrese que desea hacer: \n");
        scanf("%d",&opcion);    
        
    }
    
}


void cargar(nodo *p){
    printf("Ingrese el DNI: ");
    scanf("%d",&p->dni);
    if (p->dni==0)
    {
        p->sig=NULL;
        printf("Termino de cargar\n");
    }
    else{        
        printf("Ingrese el nombre: ");
        scanf("%s",p->nombre);
        printf("Ingrese el Saldo: ");
        scanf("%f",&p->saldo);
        p->sig=(nodo *)malloc(sizeof(nodo));
        cargar(p->sig);
    }
    
}

void mostrar(nodo *p){
    if (p->sig==NULL)
    {
        printf("Fin de lista\n");
    }
    else
    {
        printf("El saldo es %f , el dni es %d y el nombre es %s\n",p->saldo,p->dni,p->nombre);
        mostrar(p->sig);
    }
    
}

void pasar(nodo *p,nodo *n){
    while (p->sig!=NULL)
    {
        if (p->saldo<100)
        {
            n->dni=p->dni;
            strcpy(n->nombre,p->nombre);
            n->saldo=p->saldo;
            n->sig=(nodo *)malloc(sizeof(nodo));
            n=n->sig;

        }
        p=p->sig;
        
    }
    n->sig=NULL;
    

}