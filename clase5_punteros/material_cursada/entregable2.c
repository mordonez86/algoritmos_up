#include <stdio.h>

void cargar(int *vec);

void mostrar(int *vec);

void pares(int *vec,int *acum, int *cont);

int main(void) {

 int vec[20],contador=0,acumulador=0,*acum=&acumulador,*cont=&contador;

 cargar(vec);

 mostrar(vec);

 pares(vec,acum,cont);

  

 printf("\n");

 printf("la cantidad de pares fue: %i\n",contador);

 printf("la acumulacion de impares fue: %i\n",acumulador);



 printf("%i\n",vec[2]);

 printf("%p\n",*(&vec[3+2]));

 printf("%p\n",*(vec+2));

 printf("%i\n",vec[0]);

 printf("%p\n",*(vec-2));


}

void pares(int *vec,int *acum,int *cont){

 for(int i=0;i<20;i++){

  if (vec[i]%2==0){

   *cont+=1;

  }

  if (vec[i]%2!=0){

   *acum+=vec[i];

  }

 }

}

void cargar(int *vec){

 int i;

 for(i=0;i<20;i++){

  printf("ingrese un numero: ");

  scanf("%i",&*(vec+i));

 }

}

void mostrar(int *vec){

 int i;

 for(i=0;i<20;i++){

  printf("%i, %p\t",*(vec+i),vec+i);

 }

}