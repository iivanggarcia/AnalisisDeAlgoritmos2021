#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *arg[]){
	int contra, i=0, n=0, best = 0;
	printf("Ingresa el numero de aplicantes y sus calificaciones: \n");
	scanf("%d", &n);
	int cand[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", &cand[i]);
		if(cand[i] > best) 
		{
			contra++;
			best = cand[i];
			printf("aplicante %d contratado\n", i+1);
		}
	}
	printf("\nContratados: %d\n", contra);
	//printf("\nArreglo:\n{");
	//for(i=0; i<(n-1); i++) printf("%d, ", cand[i]);
	//printf("%d}", cand[n-1]);
	return 0;
}

