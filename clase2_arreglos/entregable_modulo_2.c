// Ingresar números enteros y cargar un vector con los primero 10 números positivos o hasta que se lea un cero. 
// Si el vector no tiene elementos, mostrar una leyenda, caso contrario mostrarlo y realizar las siguientes operaciones;
// a) Insertar el opuesto antes de aquellos números pares menores al promedio.
// b) Ordenar el vector de mayor a menor y mostrarlo.
#include <stdio.h>

//por prototipo
void get_array(int arr[10]);

//por prototipo
void print_array(int arr[10]);

//por prototipo
void get_conditions(int arr[10]);

//por prototipo
void sort_array(int arr[10]);

int main(){
    int arr[10];
    printf("Genero el Array: \n");
    get_array(arr);
    printf("Imprimo el Array: \n");
    print_array(arr);
    printf("Busco condiciones: \n");
    get_conditions(arr);
    sort_array(arr);
    print_array(arr);
}

//definicion de get_array
void get_array(int arr[10]){
    int numero_ingresado;
    int contador= 0;
    do{
        printf("Ingrese el Numero para la posicion %d\n",contador+1);
        scanf("%d",&numero_ingresado);
        if (numero_ingresado>0)
        {                    
        arr[contador]=numero_ingresado;
        contador+=1;
        printf("Te quedan %d numeros\n\n", 10-(contador));
        }
    }    
    while (numero_ingresado != 0 && contador <= 9);
    if (contador == 0)
    {
        printf("No ingreso ningun numero ");
    }
    
}

//definicion de print_array
void print_array(int arr[10]){
    for(int i=0; i < 10; i++){
        printf("%d\n", arr[i]);
    }

}

//definicion de get_conditions
void get_conditions(int arr[10]){
    float promedio;
    float sumatoria;

    for(int i=0;i<10;i++){
        sumatoria += arr[i];
    }
    promedio = sumatoria / 10;
    printf("el promedio es %.2f \n",promedio);

    for(int i= 0 ;i < 10 ;i++){
        if (arr[i] % 2==0 && arr[i] < promedio)
        {
            arr[i-1] = arr[i] * -1;
        };
    }

}

//definicion de sort
void sort_array(int arr[10]){
    //elegi el bubble sort por ser el mas basico

    //primero indico cuantas iteraciones voy a hacer(se elige siempre el len del array)
    int array_size=10;
    //recorro el array con i 
    for (int i = 0; i < array_size ; i++)
    {
        for (int j = 0; j < array_size-1; j++)
        {
            if (arr[j] < arr[j+1])
            {
                int temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
            
        }
        
    }
    
}