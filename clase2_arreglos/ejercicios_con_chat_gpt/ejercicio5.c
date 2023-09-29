#include <stdio.h>

int main()
{
    int arr[10]={100,20,30,-70,-50,130,65,-100,101,120};
    int anterior=arr[0];
    int grande=arr[0];

    for(int i=1;i<10;i++){
        if(arr[i]>grande){
            anterior=grande;
            grande=arr[i];
        }
        else if(arr[i]>anterior && arr[i]!=grande){
            anterior=arr[i];
        }
    }
    printf("El segundo mas grande es %d",anterior);

    return 0;
}