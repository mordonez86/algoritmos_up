#include <stdio.h>

int main()
{
    int arr[8]={-4000,4,7,1000,-200,500,700,-4000};
    int min=arr[0];
    int max=arr[0];
    for(int i =1;i<8;i++){
        if(arr[i]<min){
            min=arr[i];
        };
        if (arr[i]>max)
        {
            max=arr[i];
        }
        
    }
    printf("El minimo es %d\n",min);
    printf("El maximo es %d\n",max);
    
    return 0;
}
