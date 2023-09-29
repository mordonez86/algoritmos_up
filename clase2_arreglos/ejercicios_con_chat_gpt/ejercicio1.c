#include <stdio.h>


int main()
{
    int list[5];
    for(int i =0;i<5;i++){
        list[i]=i+1;
    };

    for(int i=0 ;i<5;i++){
        printf("El valor de i es %d en la posicion %d\n",list[i],i);
    };
    return 0;
}

