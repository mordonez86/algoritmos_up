#include <stdio.h>
#include <stdlib.h>

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
void eliminar(nodo *p, int l);
void insertar_delante(nodo *p, int l);

int main()
{
    nodo *p = (nodo *)malloc(sizeof(nodo));
    int opcion;
    do
    {
        printf("Seleccione que desea Hacer:\n1)Cargar Datos\n2)Mostrar Datos\n3)Mostrar Promedio\n4)Eliminar Con legajo\n0)Salir\n");
        scanf("%d", &opcion);
        if (opcion == 1)
        {
            cargar(p);
        }
        else if (opcion == 2)
        {
            mostrar(p);
        }
        else if (opcion == 3)
        {
            calcular_promedio(p);
        }
        else if (opcion == 4)
        {
            int legajo_borrar;
            printf("Ingrese el legajo del alumno que quiere eliminar");
            scanf("%d", &legajo_borrar);
            eliminar(p, legajo_borrar);
        }
    } while (opcion != 0);
    return 0;
}

void cargar(nodo *p)
{
    printf("Ingrese el legajo del Alumno: (0 Para Salir)\n");
    scanf("%d", &p->legajo);
    if (p->legajo == 0)
    {
        p->sig = NULL;
        printf("Termino de Cargar Datos\n");
    }
    else
    {
        printf("Ingrese nombre del alumno\n");
        scanf("%s", p->nombre);
        printf("Ingrese la edad del alumno\n");
        scanf("%d", &p->edad);
        while(p->edad < 17)
        {
            printf("la edad debe ser mayor a 17\n");
            printf("Ingrese la edad del alumno\n");
            scanf("%d", &p->edad);
        };
        printf("Ingrese Grupo de Investigacion\n");
        scanf("%d", &p->grupo);
        while(p->grupo != 1 && p->grupo != 2 && p->grupo != 3)
        {
            printf("el grupo debe ser 1 o 2 o 3\n");
            printf("Ingrese Grupo de Investigacion\n");
            scanf("%d", &p->grupo);
        };
        printf("Final Aprobado  (SI-NO)\n");
        scanf("%s", p->aprobado);
        p->sig = (nodo *)malloc(sizeof(nodo));
        cargar(p->sig);
    }
}

void mostrar(nodo *p)
{
    if (p->sig == NULL)
    {
        printf("Fin de lista\n");
    }
    else
    {
        printf("El Legajo del alumno es %d , su nombre es %s, su edad es %d , su grupo es %d y %s aprobo el final \n", p->legajo, p->nombre, p->edad, p->grupo, p->aprobado);
        mostrar(p->sig);
    }
}

void calcular_promedio(nodo *p)
{
    int contador=0;
    int total=0;
    while (p != NULL)
    {
        if (p->edad > 25 && p->edad < 30)
        {
            contador += 1;
        };
        total += 1;
        p = p->sig;
    };
    printf("El total que cumple la condicion es %d de un total de %d\n", contador,total);
}

void eliminar(nodo *p, int l)
{
    nodo *a = (nodo *)malloc(sizeof(nodo));
    while (p->sig != NULL)
    {
        if (p->legajo == l)
        {
            p->sig = a;
            free(p);
            a->sig = p->sig;
        }
        p = p->sig;
    }
}

void insertar_delante(nodo *p, int l)
{
    nodo *a = (nodo *)malloc(sizeof(nodo));
    while (p->sig != NULL)
    {
        if (p->legajo == l)
        {
            a->legajo = 9999;
            a->edad = 99;
            a->grupo = 1;
            p = a;
            a->sig = p->sig;
        }

        p = p->sig;
    }
}