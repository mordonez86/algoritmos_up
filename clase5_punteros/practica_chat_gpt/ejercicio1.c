#include <stdio.h>

int main()
{
    int x= 10;
    int *ptr= &x;
    printf("The value of x is %d , and the addres is %p",x,ptr);
    return 0;
}
