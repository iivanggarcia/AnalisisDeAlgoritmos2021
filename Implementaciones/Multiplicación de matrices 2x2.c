#include <stdio.h>
#include <stdlib.h>
#define L 2

int** squareMatrixMultiply(int a[][L], int b[][L]);
void imprime(int c[][L]);
void imprimeRes(int** c);

int main(int argc, char *arg[]){
	int a[L][L] = {2,3,4,5};
	int b[L][L] = {6,7,2,1};
	printf("a = \n");
	imprime(a);
	printf("\nb = \n");
	imprime(b);
	
	int **c,i;
	c = squareMatrixMultiply(a,b);
	
	printf("\nc = \n");
	imprimeRes(c);
	
	for(i = 0; i<L; i++)
		free(c[i]);
	free(c);
}

int** squareMatrixMultiply(int a[][L], int b[][L])
{
	int **c, i,j,k;
	int n = sizeof (a) / sizeof(int);
	c = (int **) calloc( n,sizeof(int *) );
	for(i = 0; i<n; i++)
		c[i] = (int *)calloc ( n, sizeof(int) );
	
	for(i = 0; i<n; i++)
	{
		for(j = 0; j<n; j++)
		{
			c[i][j] = 0;
			for(k= 0; k<n; k++)  c[i][j] = c[i][j] + a[i][k]*b[k][j];
		}
	}
	
	return c;
}

void imprime(int c[][L])
{
	int x,y;
	int n = sizeof (c) / sizeof(int);
	for(x = 0; x<n; x++)
	{
		for(y = 0; y<n; y++)
		{
			printf("%d ",c[x][y]);
		}
		printf("\n");
	}
}

void imprimeRes(int** c)
{
	int x,y;
	int n = sizeof (c) / sizeof(int);
	for(x = 0; x<n; x++)
	{
		for(y = 0; y<n; y++)
		{
			printf("%d ",c[x][y]);
		}
		printf("\n");
	}
}
