#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *arg[]){
	int contra=0,i=0, n=0, best = 0;
	printf("Ingresa el numero de aplicantes y sus calificaciones: \n");
	scanf("%d", &n);
	int cand[n];
	int temp;
	for(i=0; i<n; i++)	scanf("%d", &cand[i]);
	
	for(i=0; i<(n-1); i++)
	{
		srand (time(NULL));
		int r =  rand () % (n-1-i+1) + i;
		//printf("%d\n",r);
		temp = cand[r];
		cand[r] = cand[i];
		cand[i] = temp;
	}
	
	for(i=0; i<n; i++)
	{
		if(cand[i] > best) 
		{
			contra++;
			best = cand[i];
			printf("aplicante %d contratado\n", i+1);
		}
	}
	printf("\nContratados: %d\n", contra);
	return 0;
}
