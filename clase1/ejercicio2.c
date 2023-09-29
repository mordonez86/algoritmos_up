#include <stdio.h>

int main()
{
    int mes;
    int dia;
    int salir;
    float cotizacion;
    int dia_cotizacion_minima;
    float cotizacion_minima;
    
    printf("Ingrese el mes en formato Numero: ");
    scanf("%i",&mes);
    printf("Ingrese el dia: ");
    scanf("%i", &dia);
    printf("Ingrese la Cotizacion: ");
    scanf("%f",&cotizacion);

    dia_cotizacion_minima=dia;
    cotizacion_minima=cotizacion;  

    do
    {
        printf("Ingrese el dia: ");
        scanf("%i", &dia);
        printf("Ingrese la Cotizacion: ");
        scanf("%f",&cotizacion);
        if (cotizacion < cotizacion_minima)
        {
            cotizacion_minima = cotizacion;
            dia_cotizacion_minima=dia;
        }
        
        printf("Termino De ingresar los valores? (1:Si -- 2:No): ");
        scanf("%i", &salir);
    } while (salir != 1);

    printf("La cotizacion mas baja del mes %i fue el dia %i a un valor de : %f\n",mes,dia_cotizacion_minima,cotizacion_minima);
    
    return 0;
}