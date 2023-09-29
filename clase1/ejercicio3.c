#include <stdio.h>

int main()
{
    int ano;
    int ventas_anuales = 0;
    int mayor_ano;
    int max_ventas = 0;
    int total = 0;

    printf("Ingrese el Año inicial: ");
    scanf("%d", &ano);
    printf("Ingrese los autos de: %d\n", ano);
    scanf("%d", &ventas_anuales);

    total = ventas_anuales;
    mayor_ano = ano;
    max_ventas = ventas_anuales;

    for (int i = ano - 1 ; i > ano - 9 ; i--)
    {
        printf("Ingrese los autos de: %d\n", i);
        scanf("%d", &ventas_anuales);
        total += ventas_anuales;

        if (ventas_anuales > max_ventas)
        {
            mayor_ano = i;
            max_ventas = ventas_anuales;
        }
        
    }

    printf("Total: %d\n", total);
    printf("El año con mas ventas fue : %d con %d unidades vendidas\n", mayor_ano,max_ventas);
    
    return 0;
}