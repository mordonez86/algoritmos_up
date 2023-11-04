#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    int legajo;
    char nombre[20];
    int edad;
    int grupo;
    char aprobado[2];
    struct lista *sig;
} nodo;

void cargar(nodo *p);

void mostrar(nodo *p);

void calcular_promedio(nodo *p);

void insertar_delante(nodo *p, int *legajo);

int main()
{
    nodo *puntero;
    puntero = (nodo *)malloc(sizeof(nodo));
    int opcion;
    do
    {
        printf("\nSeleccione que desea hacer \n1) Cargar Datos\n2) Mostrar Datos\n3) Calcular Promedio\n4) Insertar Delante\n0) Salir\n");
        scanf("%d", &opcion);
        if (opcion == 1)
        {
            // printf("Selecciono cargar\n");
            cargar(puntero);
        }
        else if (opcion == 2)
        {
            // printf("Selecciono mostrar\n");
            mostrar(puntero);
        }
        else if (opcion == 3)
        {
            // printf("Selecciono mostrar\n");
            calcular_promedio(puntero);
        }
        else if (opcion == 4)
        {
            int legajo;
            int *l = &legajo;
            printf("Indique el legajo que quiere buscar\n");
            scanf("%d", l);
            insertar_delante(puntero, l);
        }
    } while (opcion != 0);
    return 0;
}

void cargar(nodo *p)
{
    printf("Ingrese el Numero de legajo:\n");
    scanf("%d", &p->legajo);
    if (p->legajo == 0)
    {
        p->sig = NULL;
        printf("Termino de cargar datos\n");
    }
    else
    {
        printf("Ingrese el Nombre\n");
        scanf("%s", p->nombre);
        do
        {
            printf("Ingrese Edad (solo mayores de 17 años)\n");
            scanf("%d", &p->edad);
        } while (p->edad <= 17);
        do
        {
            printf("Ingrese grupo investigacion (1,2,3)\n");
            scanf("%d", &p->grupo);
        } while ((p->grupo != 1) && (p->grupo != 2) && (p->grupo != 3));
        do
        {
            printf("Aprobo el final de Introduccion? (si,no)\n");
            scanf("%s", p->aprobado);
        } while ((strcmp(p->aprobado, "si") != 0) && (strcmp(p->aprobado, "no") != 0));

        p->sig = (nodo *)malloc(sizeof(nodo));
        cargar(p->sig);
    }
}

void mostrar(nodo *p)
{
    if (p->sig == NULL)
    {
        printf("\n---Fin de lista---\n");
    }
    else
    {
        printf("El nro de legajo es: %d, el nombre es: %s, la edad es: %d y %s aprobo el final de intro\n", p->legajo, p->nombre, p->edad, p->aprobado);
        mostrar(p->sig);
    }
}

void calcular_promedio(nodo *p)
{
    int suma = 0;
    int total = 0;
    while (p->sig != NULL)
    {
        if (p->edad > 25 && p->edad < 30)
        {
            total += 1;
        }
        suma += 1;
        p = p->sig;
    }
    printf("el promedio de alumnos que cumple la condicion es: %d\n", suma / total);
}

void insertar_delante(nodo *p, int *legajo)
{
    printf("vamos a buscar el legajo %d\n", *legajo);
    
    nodo *a = (nodo *)malloc(sizeof(nodo));

    a->legajo=9999;
    strcpy(a->nombre, "PEPE");
    a->edad=99;
    a->grupo=1;
    strcpy(a->aprobado, "si");

    while (p->sig != NULL)
    {
        if (p->legajo == *legajo)
        {
            a->sig=p->sig;
            p->sig=a;
        };
        p = p->sig;
    }
}
