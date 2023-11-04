#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int dni;
    char Nombre[20];
    char tipo_de_cuenta;
    float saldo;
    struct lista *siguiente;
}nodo;

void cargar(nodo *p);
void mostrar(nodo *p);
void buscar(nodo *p);

int main(){
    nodo *puntero=(nodo *)malloc(sizeof(nodo));
    int opcion;
    printf("Seleccione que desea hacer: ");
    scanf("%d",&opcion);
    while (opcion!=0)
    {
        if (opcion==1)
        {
                cargar(puntero);
        }
        else if (opcion ==2)
        {
               mostrar(puntero);
        }
        else if (opcion ==3)
        {
            buscar(puntero);
        }
        else{
        }
        printf("Seleccione que desea hacer: ");
        scanf("%d",&opcion);       
        
    }
    





   
}

void cargar(nodo *p){
    printf("Ingrese el DNI: ");
    scanf("%d",&p->dni);
    if (p->dni==0)
    {
        p->siguiente=NULL;
        printf("Fin de carga\n");
    }
    else{
        while (p->dni>99999999)
        {
            printf("el dni debe ser menor a 8 digitos");
            printf("Ingrese el DNI: ");
            scanf("%d",&p->dni);
        }        
        printf("Ingrese el nombre: ");
        scanf("%s",p->Nombre);
        p->siguiente=(nodo *)malloc(sizeof(nodo));
        cargar(p->siguiente);
    }
    
}

void mostrar(nodo *p){
    if (p->siguiente==NULL)
    {
        printf("Fin de lista\n");
    }
    else{
        printf("El dni es %d y el nombre es %s\n",p->dni,p->Nombre);
        mostrar(p->siguiente);
    }
    
}

void buscar(nodo *p){
    int nro_dni=0;
    printf("Ingrese el numero a buscar: ");
    scanf("%d",&nro_dni);
    while (p->siguiente!=NULL)
    {
        if (p->dni==nro_dni)
        {
            printf("Esta el numero %d , pertenece a %s\n",nro_dni,p->Nombre);
        }
        p=p->siguiente;
    }
    
}