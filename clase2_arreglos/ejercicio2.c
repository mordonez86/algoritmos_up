#include <stdio.h>



void genero_array(int numeros[10]){
    int indice_positivos = 0;
    int indice_negativos = 5 ; 
    int numero_ingresado ;  
    while(indice_positivos < 5 || indice_negativos < 10){
        printf("Ingrese el numero: ");
        scanf("%d", &numero_ingresado);
        if (numero_ingresado >= 0 )
        {
            numeros[indice_positivos]=numero_ingresado;
            printf("El numero ingresado fue positivo y es : %d\n", numero_ingresado);
            indice_positivos+=1;
        }
        else
        {
            numeros[indice_negativos]=numero_ingresado;
            printf("El numero ingresado fue negativo y es : %d\n", numero_ingresado);
            indice_negativos+=1;
        }
    }
}

void ordeno_array(int numeros[10]){
    //elegi el bubble sort por ser el mas basico

    //primero indico cuantas iteraciones voy a hacer(se elige siempre el len del array)
    int array_size=10;
    //recorro el array con i 
    for (int i = 0; i < array_size ; i++)
    {
        for (int j = 0; j < array_size-1; j++)
        {
            if (numeros[j]>numeros[j+1])
            {
                int temp = numeros[j];
                numeros[j]=numeros[j+1];
                numeros[j+1]=temp;
            }
            
        }
        
    }
    
}

void imprimo_array(int numeros[10]){
for(int i=0;i<10;i++){
        printf("%d\n", numeros[i]);
        
    }
}

void imprimo_mayores(int numeros[10]){
    for(int i=9;i>5;i--){
        printf("%d\n", numeros[i]);
        
    }
}

void genero_array_intercalado(int numeros[10], int intercalados[10]){
    int indice_negativos=0;
    int indice_positivos=9;
    for(int i = 0;i < 10;i++){
        if(i%2==0){
            intercalados[i]=numeros[indice_negativos];
            indice_negativos+=1;
        }
        else{
            intercalados[i]=numeros[indice_positivos];
            indice_positivos-=1;
        }
    }

}

int main(){
    int numeros[10] ;
    int numeros_intercalados[10];
    genero_array(numeros);
    printf("Imprimo el resultado\n");
    imprimo_array(numeros);  
    printf("Ordeno resultado\n");
    ordeno_array(numeros);
    printf("Imprimo Ordenado\n");
    imprimo_array(numeros);
    printf("Imprimo los 4 Mayores\n");
    imprimo_mayores(numeros);
    printf("Creo nuevo array con numeros intercalados\n");
    genero_array_intercalado(numeros,numeros_intercalados);
    printf("Imprimo el array de intercalados\n");
    imprimo_array(numeros_intercalados);
    return 0;
}