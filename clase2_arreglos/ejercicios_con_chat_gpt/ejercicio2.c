#include <stdio.h>

int main()
{
    int arreglo[10];
    int posicion =0;
    for (int i = 0; i < 21; i++)
    {
     if (i%2==0)
     {
        arreglo[posicion]=i;
        posicion++;
     }
     
    };
for (int k = 10; k >=0; k--)
{
    printf("En la posicion %d el valor es %d\n", k, arreglo[k]);
}
return 0;
}