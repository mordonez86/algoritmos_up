// Contenido de la actividad

// Escriba un programa que permita registrar las ventas y los productos que se venden en un pequeño supermercado de barrio.

// De los productos se guarda la siguiente información:

// ID producto
// Nombre del producto
// Precio
// Contenido neto/ Cantidad
// Crear un programa que calcule el valor que debe pagar el cliente, en base a los productos que desea llevar, así como el producto más vendido.

// Al comenzar el día el dueño de la tienda, carga los nuevos productos que tiene para vender.
// El dueño del local va a atender 10 clientes en el día o hasta que el id del cliente sea igual a 0 (cero).
// Cada cliente puede llevar la cantidad de productos que desee siempre que sea mayor a cero y menor a 100.
// Se debe calcular y mostrar el precio total (cantidad × precio) de cada producto elegido. Pueden hacerlo creando otra lista que guarde solo los precios totales según el producto.
// Mostrar una lista de todos los productos disponibles. Para esto se puede usar la lista creada anteriormente o usando su imaginación.
// IMPORTANTE: El programa debe contar con un menú que permita seleccionar que se desea hacer.

#include <stdio.h>
#include <stdlib.h>

// aca se crean dos punteros ,uno interno que es parte del tpo de datos y lo que hace es apuntar al proximo nodo
// el segundo puntero es el que apunta solamente al primer espacio en memoria de la estructura

// defino el tipo de dato 
typedef struct venta{
    int numero;
    int idProducto;
    char nombre_producto[50];
    char contenido_neto[50];

    struct lista *sig;    
}nodo;





//prototipo de funciones
//crear recibe el puntero de tipo nodo que declaramos en main
void crear(nodo *puntero);
void mostrar(nodo *puntero,int *p_total_ventas);


int main(){
    // defino el puntero con el mismo tipo de dato definido mas arriba (nodo)
    nodo *p;
    int total_ventas=0;
    int *p_total_ventas= &total_ventas;
    p=(nodo*)malloc(sizeof(nodo));
    // crear(p);
    // mostrar(p,p_total_ventas);
    // printf("las ventas totales fueron: %d",total_ventas);
    do
    {
        /* code */
    }
    
    return 0;

}

//definicion de funcion crear
void crear(nodo *puntero){
    printf("Ingrese la cantidad vendida del producto: ");
    scanf("%d",&puntero->numero);
    printf("Ingrese el ID del Producto: ");
    scanf("%d",&puntero->idProducto);
    printf("Ingrese el nombre del producto: ");
    scanf("%s", &puntero->nombre_producto);
    printf("Ingrese el contenido neto/cantidad del producto: ");
    scanf("%s", &puntero->contenido_neto);

    if(puntero->numero == 0){
        puntero->sig = NULL;
    }
    else{
        puntero->sig = (nodo *)malloc(sizeof(nodo));
        crear(puntero->sig);
    }
}

//definicion de funcion mostrar
void mostrar(nodo *puntero,int *p_total_ventas) {
    if (puntero == NULL) {
        printf("NULL\n");
    }

    printf("del Producto nombre %d con el id %d se vendio %d ", puntero->nombre_producto , puntero->idProducto, puntero->numero);
    *p_total_ventas += puntero->numero;
    mostrar(puntero->sig,p_total_ventas);
}

