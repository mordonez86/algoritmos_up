
// a) Crear y mostrar la lista (la carga finaliza cuando codmat=0). Se cargan todos loscódigos de materias iguales seguidos y ordenados.
// b) Mostrar los alumnos que pertenecen a una materia.
// c) Mostrar el código de materia que cuenta con más alumnos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    int codmat;
    char nombre[15];
    int alumnos;

    struct lista *sig;
}nodo;

void cargar(nodo *p);
void mostrar(nodo *p);
void buscar(nodo *p);
void mas_alumnos(nodo *p);

int main()
{
    nodo *puntero=(nodo *)malloc(sizeof(nodo));
    int opcion;
    printf("Seleccione que desea: \n");
    scanf("%d",&opcion);
    while (opcion != 0)
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
            buscar(puntero);
        }
        else if (opcion ==4)
        {
            mas_alumnos(puntero);
        }
        printf("Seleccione que desea: \n");
        scanf("%d",&opcion);
        
    }


    return 0;
}

void cargar(nodo *p){
    printf("Ingrese el codigo de materia: ");
    scanf("%d",&p->codmat);
    if (p->codmat==0)
    {
        printf("fin de carga\n");
        p->sig=NULL;
    }
    else{
        printf("Ingrese el nombre: ");
        scanf("%s",p->nombre);
        printf("Ingrese la cantidad de alumnos: ");
        scanf("%d",&p->alumnos);
        p->sig=(nodo *)malloc(sizeof(nodo));
        cargar(p->sig);
    }
    
}


void mostrar(nodo *p){
    if (p->sig==NULL)
    {
        printf("Fin de lista\n");
    }
    else{
        printf("La materia %s tiene %d alumnos\n",p->nombre,p->alumnos);
        mostrar(p->sig);
    }
}


void buscar(nodo *p){
    int materia;
    printf("Ingrese el codigo de materia a buscar\n");
    scanf("%d",&materia);
    while (p->sig!=NULL)
    {
        if (p->codmat==materia)
        {
            printf("Encontrado!!!\n El codigo es %d y el nombre es %s\n",materia,p->nombre);
        }
        
        p=p->sig;
    }
}

void mas_alumnos(nodo *p){
    int mayor=p->alumnos;
    char materia_mayor[15];
    do
    {
        if (p->alumnos>mayor)
        {
            mayor=p->alumnos;
            strcpy( materia_mayor,p->nombre);

        }
        p=p->sig;
    } while (p->sig!=NULL);
    printf("El curso con mas alumnos es : %d y es %s\n",mayor,materia_mayor);
}