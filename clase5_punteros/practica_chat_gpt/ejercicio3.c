#include <stdio.h>


int main(){
    int num= 42;
    int *ptr= &num;

    *ptr=100;

    printf("%d\n",num);
    printf("%d in the memory %p",*ptr,*ptr);


}