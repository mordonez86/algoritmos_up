// crear una lista e insertar un valor delante de una condicion (de los id pares)

#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int id;
    char nombre[20];
    struct lista *siguiente;
}nodo;

void cargar(nodo *p);
void mostrar(nodo *p);
void procesar(nodo *p);
nodo* insertar_principio(nodo *p);
nodo* eliminar_id_cabeza(nodo *p);


int main(){
    nodo *puntero=(nodo*)malloc(sizeof(nodo));
    int opcion;

    printf("Ingrese que desea: ");
    scanf("%d",&opcion);
    while (opcion!=0)
    {
        if (opcion==1)
        {
            printf("uno\n");
            cargar(puntero);
        }
        else if (opcion==2)
        {
            printf("dos\n");
            mostrar(puntero);
        }
        else if (opcion==3)
        {
            printf("tres\n");
            procesar(puntero);
        }
        else if (opcion==4)
        {
            printf("cuatro\n");
            puntero=insertar_principio(puntero);
        }
        else if (opcion==5)
        {
            printf("cinco\n");
            puntero=eliminar_id_cabeza(puntero);
        }
        printf("Ingrese que desea: ");
        scanf("%d",&opcion);
    }
    return 0;
}

void cargar(nodo *p){
    printf("Ingrese el ID: ");
    scanf("%d",&p->id);
    if (p->id==0)
    {
        p->siguiente=NULL;
        printf("Termino de cargar\n");
    }
    else
    {
        printf("Ingrese el nombre: ");
        scanf("%s",p->nombre);
        p->siguiente=(nodo *)malloc(sizeof(nodo));
        cargar(p->siguiente);
    }
    
}

void mostrar(nodo *p){
    if (p->siguiente==NULL)
    {
        printf("Fin de lista\n");
    }
    else
    {
        printf("El id es %d y el nombre es %s\n",p->id,p->nombre);
        mostrar(p->siguiente);
    }
    
}



void procesar(nodo *p){
    while (p->siguiente!=NULL)
    {
        if (p->id%2==0)
        {
            nodo *aux=(nodo *)malloc(sizeof(nodo));
            printf("%d es par",p->id);
            printf("Entonces ingrese el nuevo id: ");
            scanf("%d",&aux->id);
            printf("ingrese el nuevo nombre: ");
            scanf("%s",aux->nombre);
            aux->siguiente=p->siguiente;
            p->siguiente=aux;
        }
        
        p=p->siguiente;
    }
}

nodo* insertar_principio(nodo *p){
    nodo *aux=(nodo *)malloc(sizeof(nodo));
    printf("Ingrese el ID a insertar: ");
    scanf("%d",&aux->id);
    printf("Ingrese el nombre a insertar");
    scanf("%s",aux->nombre);
    aux->siguiente=p;
    return aux;
}

nodo* eliminar_id_cabeza(nodo *p){
    int id_delete;
    printf("Ingrese el ID a eliminar: ");
    scanf("%d",&id_delete);

    while (p->siguiente!=NULL)
    {
        if (p->id==id_delete)
        {
        nodo *aux=(nodo *)malloc(sizeof(nodo));
        aux=p->siguiente;
        free(p);
        p=aux;
        return p;
        }
        p=p->siguiente;
    }
    
}