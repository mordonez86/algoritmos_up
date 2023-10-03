#include <stdio.h>

int main()
{
    int x = 15;
    int *ptr = &x;
    int *y= &x;
    *ptr= 30;
    printf("x = %d , y = %d , ptr = %p",x,*y,*ptr);

    return 0;
}