#include <stdio.h>




int main()
{
    int *punt;
    int x=7;
    int y=5;

    punt=&x;
    x=4;
    punt=&y;

    printf("%d, %d",*punt,x);
    return 0;
}


//este codigo asigna el valor de x al puntero , luego cambia el valor de x y asigna al puntero el valor de Y 
// el printf nos imprime el nuevo valor de x y tambien el valor de Y