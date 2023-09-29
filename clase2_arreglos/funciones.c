#include <stdio.h>


//en c las funciones se declarna entre las librerias y el main 
// si es por prototipo , puedo definirla en el encabezado , poniendo su nombre el tipo de dato que devuelve y el tipo de dato que recibe y puedo declarar el codigo al final
// si es por desarrollo , se desarrolla directamente arriba


int sumar(int, int);
int multiplicar(int, int);
int restar(int a,int b){
    int resultado = a-b;
    return resultado;
}
int dividir(int a, int b){
    int resultado = a / b ;    
    return resultado;
}

int main()
{
    int num1 = 6;
    int num2 = 6;
    int resuma ;
    int reresta ;
    int redivision ;
    int remultiplicacion ;
    resuma =  sumar(num1,num2);
    reresta = restar(num1,num2);
    redivision = dividir(num1,num2);
    remultiplicacion = multiplicar(num1,num2);
    printf("el resultado de la suma es %d\n",resuma);
    printf("el resultado de la resta es %d\n",reresta);
    printf("el resultado de la division es %d\n",redivision);
    printf("el resultado de la multiplicacion es %d\n",remultiplicacion);
    return 0;
}

int sumar(int a , int b){
    int resultado = a + b;
    return resultado;
}

int multiplicar(int a , int b){
    int resultado = a * b;
    return resultado;
}