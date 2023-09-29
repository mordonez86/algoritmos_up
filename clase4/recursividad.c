// una funcion recursiva tiene 2 partes , en una se pone la condicion (caso base) de salida con return 1 ( este uno se lo va a devolver a la funcion en si )
// en la otra se pone la operacion general (caso general)

// en c en la ejecucion del codigo , primero se almacenan todas las ejecuciones de la funcion hasta llegar al caso base y luego se van resolviendo


//create factorial function in c

int factorial(int numero){
    if (numero==1){
        return 1;
    }
    else{
        return numero*factorial(numero-1);
    }
}

int main(int argc, char const *argv[])
{
    int numero = 5;
    printf("El factorial de %d es %d\n", numero, factorial(numero));
    return 0;
    }
