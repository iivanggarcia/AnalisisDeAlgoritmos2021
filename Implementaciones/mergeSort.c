/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void printA(int A[], int size);

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7, 4, 67, 23, 2, 0, 12, -3, -6, 2, 7, 4 };
	int tam = sizeof(arr) / sizeof(arr[0]);

	printf("Arreglo original \n");
	printA(arr, tam);

	mergeSort(arr, 0, tam - 1);

	printf("Arreglo ordenado \n");
	printA(arr, tam);
	return 0;
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void printA(int A[], int tam)
{
	int i;
	for (i = 0; i < tam; i++)
		printf("%d ", A[i]);
	printf("\n");
}

