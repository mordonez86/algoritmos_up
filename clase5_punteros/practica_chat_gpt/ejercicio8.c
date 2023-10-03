#include<stdio.h>



void calcular(int *ptr_array,int *ptr_result){
    int resultado=0;
    for(int i=0;i<5;i++){
        resultado+=*(ptr_array+i);
    }
    *ptr_result=resultado;
    

}

int main()
{
    int arr[5]={5,10,15,20,25};
    int result;
    int *ptr_array=arr;
    int *ptr_result=&result;
    printf("el valor es %d y esta en la memoria %p\n",*ptr_array,ptr_array);
    calcular(ptr_array,ptr_result);
    printf("El resultado de la suma total es: %d",result);
    return 0;
}
