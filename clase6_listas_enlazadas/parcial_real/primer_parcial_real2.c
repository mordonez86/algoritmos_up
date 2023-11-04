#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    int legajo;
    char nombre[20];
    int edad;
    int grupo;
    char final_aprobado[2];
    struct lista *sig;
} nodo;

void cargar(nodo *p);
void mostrar(nodo *p);
void calcular(nodo *p);

int main()
{
    nodo *prin = (nodo *)malloc(sizeof(nodo));
    int opcion;
    do
    {
        printf("Seleccione que desea hacer:\n1) Cargar Datos\n2) Mostrar Datos\n3) Mover Datos\n4) Calcular Promedio\n5) Eliminar con Legajo\n6) Insertar Delante\n0) Salir\n");
        scanf("%d", &opcion);
        if (opcion == 1)
        {
            printf("mostrar\n");
            cargar(prin);
        }
        else if (opcion == 2)
        {
            printf("dos\n");
            mostrar(prin);
        }
        else if (opcion == 3)
        {
            printf("tres\n");
        }
        else if (opcion == 4)
        {
            printf("cuatr\n");
            calcular(prin);
        }
        else if (opcion == 5)
        {
            printf("cinco\n");
        }
        else if (opcion == 6)
        {
            printf("seis\n");
        }

    } while (opcion != 0);

    return 0;
}

void cargar(nodo *p)
{
    printf("ingrese el nro de legajo (0 Para terminar)\n");
    scanf("%d", &p->legajo);
    if (p->legajo == 0)
    {
        p->sig = NULL;
        printf("Termino de cargar !\n");
    }
    else
    {
        printf("Ingrese el Nombre:\n");
        scanf("%s", p->nombre);
        do
        {
            printf("Ingrese Edad:\n");
            scanf("%d", &p->edad); /* code */
        } while (p->edad < 17);
        do
        {
            printf("Ingrese Grupo:\n");
            scanf("%d", &p->grupo); /* code */
        } while (p->grupo != 1 && p->grupo != 2 && p->grupo != 3);
        do
        {
            printf("Aprobo el Final?\n");
            scanf("%s", p->final_aprobado); /* code */
        } while (strcmp(p->final_aprobado, "si") && strcmp(p->final_aprobado, "no"));

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
        printf("El nro de legajo es: %d, el nombre es: %s, la edad es: %d pertenece al grupo %d y %s aprobo el final de intro\n", p->legajo, p->nombre, p->edad, p->grupo, p->final_aprobado);
        mostrar(p->sig);
    }
}

void calcular(nodo *p){
    int total;
    int suma;

    while (p->sig!=NULL)
    {
        if (p->edad>25&&p->edad<30)
        {
            printf("la edad es %d\n",p->edad);
            suma+=p->edad;
        }    
        total+=1;    
        p=p->sig;
    }
    printf("la suma de las edades es %d\n",suma);
    printf("el total de registros es %d\n",total);

}
