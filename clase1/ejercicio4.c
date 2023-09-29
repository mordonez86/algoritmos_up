#include <stdio.h>

int main()
{
    int input = 0;
    int mayores_a_4 = 0 ;
    int multiplos_6 = 0;
    int total_multiplos_6 = 0;
    int menor = 0;
    float promedio = 0;

    printf("ingrese el numero: ");
    scanf("%i",&input);
    menor = input;
    do
    {
        if (input > 4 && input < 25)
        {
            mayores_a_4 ++;
        };
        if (input % 6 == 0)
        {
            multiplos_6 += input;
            total_multiplos_6 ++;
        };
        if (input < menor)
        {
            menor = input;
        }
        
        printf("ingrese el numero: ");
        scanf("%i",&input);
    } while (input >= 0);
    
    if (total_multiplos_6 > 0)
    {
        promedio = multiplos_6 / total_multiplos_6;
    }
    
    printf("el total de mayores es: %i\n",mayores_a_4);
    printf("el promedio de los multiplos de 6 es: %f\n", promedio);
    printf("el Menor numero fue: %i\n", menor);
    
    
    printf("termino");
    return 0;
}