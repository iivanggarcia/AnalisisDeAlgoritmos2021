#include <stdio.h>
#include <stdlib.h>

/* Programa para generar numeros aleatorios y ordenarlos */

int main(int argc, char *argv[]) {
	int num;
	
	printf("Escribe cuantos numeros quieres ordenar\n");
	scanf("%d", &num);
	
	int numeroAleatorio[num-1]; //Indices de 0 a num-1, resultan num numeros
    int i;

    srand (time(NULL));
    for (i=0; i<=num-1; i++) {
        numeroAleatorio[i] = rand()% 1000;
    }
    
	int j, k,temp;
   	for (j = 0; j < num-1; j++){
		for (k = 0; k < num-j-1; k++) {
			if (numeroAleatorio[k] > numeroAleatorio[k+1]){
           		temp = numeroAleatorio[k];
			    numeroAleatorio[k] = numeroAleatorio[k+1];
			    numeroAleatorio[k+1] = temp;
		   }
		   }
	   }
    
    printf("Los %d numeros ordenados son: \n", num);
    for (i=0; i<=num-2; i++) {
        printf("%d, ", numeroAleatorio[i]);
    }
    printf("%d\n ", numeroAleatorio[num-1]);
    
	return 0;
}
