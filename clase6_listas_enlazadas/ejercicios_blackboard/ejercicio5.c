#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int dni;
    char nombre[20];
    float saldo;
    struct lista *sig;
}nodo;



void cargar(nodo *p);
void mostrar(nodo *p);
//void pasar(nodo *p);




int main()
{
    nodo *puntero=(nodo *)malloc(sizeof(nodo));
    int opcion;

    printf("Ingrese que desea hacer: ");
    scanf("%d",&opcion);


    while (opcion!=0)
    {
        if (opcion==1)
        {
            cargar(puntero);
        }
        else if (opcion==2)
        {
            mostrar(puntero);
        }
        else if (opcion==3)
        {
            // pasar(puntero);
        }
        printf("Ingrese que desea hacer: ");
        scanf("%d",&opcion);    
        
    }
    
}


void cargar(nodo *p){
    printf("Ingrese el DNI: ");
    scanf("%d",&p->dni);
    if (p->dni==0)
    {
        p->sig=NULL;
        printf("Termino de cargar");
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
        printf("Fin de lista");
    }
    else
    {
        printf("El saldo es %f , el dni es %d y el nombre es %s\n",p->saldo,p->dni,p->nombre);
        mostrar(p->sig);
    }
    
}