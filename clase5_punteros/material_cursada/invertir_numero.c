#include<stdio.h>
 
//Swap function to swap 2 numbers
void swap(int *num1, int *num2) {
   int temp;
   //Copy the value of num1 to some temp variable
   temp = *num1;
 
   //Copy the value of num2 to num1
   *num1 = *num2;
 
   //Copy the value of num1 stored in temp to num2
   *num2 = temp;
}
 
int main() {
   int num1, num2;
 
   //Inputting 2 numbers from user
   printf("\nEnter the first number : ");
   scanf("%d", &num1);
   printf("\nEnter the Second number : ");
   scanf("%d", &num2);
 
   //Passing the addresses of num1 and num2
   swap(&num1, &num2);
 
   //Printing the swapped values of num1 and num2
   printf("\nFirst number  : %d", num1);
   printf("\nSecond number : %d", num2);
 
   return (0);
}