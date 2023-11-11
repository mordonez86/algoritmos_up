#include <stdio.h>

#include <stdlib.h>

typedef struct tiponodo

{
    int dato;

    struct tiponodo *siguiente;

} nodo;

void mostrar(nodo aux)

{

    printf("%d \n", aux.dato);
}

nodo *crear_nodo(int dato)

{

    nodo *u;

    u = (nodo *)malloc(sizeof(nodo));

    u->dato = dato;

    u->siguiente = NULL;

    return u;
}

void apilar(nodo **p, nodo *u)

{

    printf("apilar_nodo\n");

    u->siguiente = *p;

    printf("%02d p=%X u=%X\n", u->dato, *p, u);

    *p = u;
}

nodo desapilar(nodo **p)

{

    nodo *aux;

    nodo datos;

    datos = **p;

    aux = *p;

    *p = (*p)->siguiente;

    free(aux);

    return datos;
}


int main()

{

    int num;
    int posicion=0;
    int impar=0;
    int multiplos_5=0;
    int acumulador=0;

    nodo *p = NULL;

    printf("Ingrese un numero \n");

    scanf("%d", &num);

    while (num!=-1)
    {
        apilar(&p, crear_nodo(num));
        printf("Ingrese un numero \n");

        scanf("%d", &num);
    }
    


    printf("\nVamos a desapilar todo\n");

    while (p != NULL)

    {
        posicion+=1;
        nodo digito=desapilar(&p);
        if (posicion%2!=0)
        {
            printf("En la posicion %d el numero es %d\n",posicion,digito.dato);
            impar+=1;
            if (digito.dato%5==0)
            {
                multiplos_5+=1;
                acumulador+=digito.dato;
                printf("En la posicion %d el numero %d es multiplo de 5\n",posicion,digito.dato);

            }
            
        }
        
        
    }
    if (impar==multiplos_5)
    {
        printf("la sumatoria total es %d",acumulador);
    }
    else{
        printf("El promedio es %d",(acumulador/impar));
    }
    

    return 0;
}