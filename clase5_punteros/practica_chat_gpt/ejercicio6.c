#include<stdio.h>


void swap(int *ptra,int *ptrb){
    int temp=*ptra;
    *ptra=*ptrb;
    *ptrb=temp; 
}

int main()
{
    int a=100;
    int b=200;
    int *ptra=&a;
    int *ptrb=&b;
    printf("Los valores eran %d , y %d \n",a,b);
    int temp=*ptrb;
    *ptrb=*ptra;
    *ptra=temp;
    printf("ahora son  %d , y %d \n",a,b);
    swap(ptra,ptrb);
    printf("y los volvi a inventir ahora son  %d , y %d \n",a,b);

    return 0;
}
