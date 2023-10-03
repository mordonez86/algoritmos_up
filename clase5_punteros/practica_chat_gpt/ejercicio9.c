#include <stdio.h>
#include <stdlib.h>


void promedio(int *ptr_array,float *ptr_promedio){
    int suma_total;
    float promedio;
    for(int i=0;i<5;i++){
        suma_total+=*(ptr_array+i);
    };
    printf("la suma total es: %d\n",suma_total);
    promedio=suma_total/5.0;
    *ptr_promedio=promedio;

}

int main()
{
    int array[]={3,8,12,17,22};
    int *ptr=array;
    float prom;
    float *ptr_promedio=&prom;
    promedio(ptr,ptr_promedio);
    printf("El promedio es %f",prom);

    return 0;
}
