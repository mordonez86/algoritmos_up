#include <stdio.h>

int main(){
    int a=20;
    int b=30;
    int *ptra= &a;
    int *ptrb= &b;
    
    int temp = *ptra;

    *ptra= *ptrb;
    *ptrb= temp;

    printf("El valor de A es %d\n",a);
    printf("El valor de B es %d",b);
    


    return 0;
}

