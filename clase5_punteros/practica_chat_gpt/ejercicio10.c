#include<stdio.h>



void reverse(char *ptr){
    int letra=5;
    char temp;
    for(int i=0;i<3;i++){
        temp = *(ptr+i);
        *(ptr+i) = *(ptr+letra);
        *(ptr+letra) = temp;
        letra--;
    }
}



int main()
{
    char str[]="OpenAI";
    char *ptr=str;
    reverse(ptr);
    printf("%s",str);


}
