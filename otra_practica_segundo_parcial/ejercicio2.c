#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef struct tiponodo
{
    int peso_del_archivo;
    char nombre_del_archivo[20];

    struct tiponodo *siguiente_archivo;

} nodo;

void mostrar(nodo aux)

{

    printf("Mostrado el archivo: %s \n", aux.nombre_del_archivo);
}

nodo *crear_nodo(int peso,char *nombre)

{

    nodo *u;

    u = (nodo *)malloc(sizeof(nodo));

    u->peso_del_archivo = peso;
    strcpy(u->nombre_del_archivo, nombre);

    u->siguiente_archivo = NULL;

    return u;
}

void apilar(nodo **p, nodo *u)

{

    printf("apilar_nodo\n");

    u->siguiente_archivo = *p;

    printf("Guardado\n");

    *p = u;
}

nodo desapilar(nodo **p)

{

    nodo *aux;

    nodo datos;

    datos = **p;

    aux = *p;

    *p = (*p)->siguiente_archivo;

    free(aux);

    return datos;
}

int main()

{

    int i, num;
    char nombre[20];

    nodo *p = NULL;

    for (i = 0; i < 10; i++)

    {

        printf("Ingrese el Tamaño del archivo \n");

        scanf("%d", &num);
        printf("Ingrese el nombre del archivo\n");
        scanf("%s",nombre);
        apilar(&p, crear_nodo(num,nombre));
    }

    printf("\nVamos a desapilar todo\n");

    while (p != NULL)

    {

        mostrar(desapilar(&p));
    }

    return 0;
}