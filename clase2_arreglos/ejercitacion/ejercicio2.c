#include <stdio.h>



int main()
{
    int array[5];
    
    for(int i = 0; i < 5 ; i++){
        printf("ingrese para la posicion %d",i);
        scanf("%d", &array[i]);
    };

    for(int i = 0; i < 5; i++){
        printf("Your Input Was: %d\n",array[i]);
    }
    return 0;
}
