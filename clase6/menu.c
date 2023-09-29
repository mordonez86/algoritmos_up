#include <stdio.h>
#include <stdlib.h>



typedef struct producto
{
    int idProducto;
    char nombre_producto[20];
    float precio;
    int contenido_neto;
    struct producto *sig;
} producto;

typedef struct venta
{
    int idProducto;
    int cantidad;
    float precio;
    struct venta *sig;
} venta;

void cargar_productos(producto *puntero)
{
    printf("\ncargando datos\n");
    printf("Ingrese el ID del Producto: ");
    scanf(" %d", &puntero->idProducto);

    if (puntero->idProducto == 0)
    {
        puntero->sig = NULL;
    }
    else
    {
        printf("Ingrese el nombre del producto: ");
        scanf("%s", &puntero->nombre_producto);
        printf("Ingrese el precio del producto: ");
        scanf("%f", &puntero->precio);
        printf("Ingrese el contenido neto/cantidad del producto: ");
        scanf("%d", &puntero->contenido_neto);
        puntero->sig = (producto *)malloc(sizeof(producto));
        cargar_productos(puntero->sig);
    }
};

// definicion de funcion mostrar
void mostrar_productos(producto *puntero)
{
    if (puntero == NULL)
    {
        return;
    }

    if (puntero->sig != NULL)
    {
        printf("Producto nombre %s ,id %d\n", puntero->nombre_producto, puntero->idProducto);
        mostrar_productos(puntero->sig);
    }
}

void mostrar_ventas(venta *puntero)
{

    if (puntero != NULL && puntero->idProducto != 0)
    {
        printf("Producto id %d, cantidad %d, precio %.2f, precio Final %.2f\n", puntero->idProducto, puntero->cantidad, puntero->precio, puntero->cantidad * puntero->precio);
    }


    if (puntero != NULL && puntero->sig != NULL)
    {
        mostrar_ventas(puntero->sig);
    }
}

void agregar_ventas(producto *productos, venta *ventas)
{
    int id;
    printf("Ingrese el ID del producto a vender: ");
    scanf("%d", &id);

    //temporal , porque sino , al segundo ingreso de ventas me daba error, revisar....
    producto *temp = productos;

    while (temp != NULL)
    {
        if (temp->idProducto == id)
        {
            venta *nueva_venta = (venta *)malloc(sizeof(venta));
            nueva_venta->idProducto = id;
            printf("Ingrese la cantidad a vender: ");
            scanf("%d", &nueva_venta->cantidad);
            nueva_venta->precio = temp->precio;
            nueva_venta->sig = ventas->sig;
            ventas->sig = nueva_venta;
            printf("Venta agregada exitosamente.\n");
            return;
        }
        temp = temp->sig;
    }
    printf("Producto no encontrado.\n");
}

int main()
{
    int seleccion;
    producto *p;
    venta *v;
    p = (producto *)malloc(sizeof(producto));
    v = (venta *)malloc(sizeof(venta));
    do
    {
        printf("\nQue desea hacer:\n1)Ingresar Productos\n2)Ingresar Venta Nueva\n3)Imprimir Productos\n4)Mostrar Ventas\n");
        scanf("%d", &seleccion);
        if (seleccion == 1)
        {
            cargar_productos(p);
            mostrar_productos(p);
        }
        else if (seleccion == 2)
        {
            agregar_ventas(p, v);
        }
        else if (seleccion == 3)
        {
            mostrar_productos(p);
        }
        else if (seleccion == 4)
        {
            mostrar_ventas(v);
        }
    } while (seleccion != 0);
    return 0;
}
