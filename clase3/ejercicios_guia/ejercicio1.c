//1. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar cuántas palabrastienen más de 3 letras.
#include <stdio.h>




int main(){ 
    char caracter;
    int count=0;
    int cant_letras=0;

    printf("Ingrese la Frase\n");
    caracter=getchar();        

// primero recorro  y verifico que no sea un punto
    while(caracter!='.'){
        // luego recorro y verifico que no sea un espacio
        while (caracter==' ')
        //aca pude ubicar el reiniciar a 0 el contador de cant de letras gracias al debugger
        {
            cant_letras=0;            
            caracter=getchar();
            
        }
            while (caracter!='.' && caracter!=' ')
            {
                //cambie de lugar cant de letras porque abajo lo contaba despues de llegar , gracias al debugger
            cant_letras +=1;
            caracter=getchar();
            if( caracter==' '|| caracter=='.'){
                if (cant_letras>3)
                {
                count +=1;
                }                
                }
            }            
        }
    printf("\nIngreso %d palabras", count);

    return 0;
}