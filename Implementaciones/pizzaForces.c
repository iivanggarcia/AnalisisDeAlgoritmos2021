#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *arg[]){
	int i, numtest;
	unsigned long long n;
	
	scanf("%d", &numtest);
	unsigned long long test[numtest];
	unsigned long long res[numtest];
	
	for(i= 0; i<numtest; i++){
		scanf("%lld", &test[i]);
		n=0;
		if(test[i]<6) n=6;
		else n = test[i] + test[i]%2;
		res[i] = n*2.5;
	}
	for(i= 0; i<numtest; i++){
		printf("%lld\n", res[i]);
	}
	return 0;
}
