#include<stdio.h>

int main()
{
    char arr[6]="hello";
    char *ptr=arr;
    // printf("%s",arr);
    for(int i=0;i<6;i++){

    printf("%c\n",*(ptr+i));
    }
    return 0;
}
