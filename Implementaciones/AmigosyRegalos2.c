#include <stdio.h>
#include <stdlib.h>

long long maxAmigo1( long long c,  long long x);
long long max( long long a,  long long b);
long long maxAmigo2( long long c1,  long long c2,  long long x,  long long y);
long long mcm( long long a,  long long b);
long long mcd( long long a,  long long b);

long long multip= 0;
long long res1 = 0;

int main(){
	 long long c1 = 0, c2 = 0, x = 0, y = 0;
	 long long a,b;
	scanf("%lld %lld %lld %lld", &c1, &c2, &x, &y);
	
	res1 = maxAmigo1(c1,x);
	//printf("%d\n", res1);
	b = maxAmigo2(c1, c2,x,y);
	//printf("%d\n", b);
	
	printf("%lld", max(res1,b));
	return 0;
}

long long maxAmigo1(long long c, long long x){
	long long mult = c/x;
	if(c%x != 0)
		mult++;
	long long res= x*mult;
	
	while(1){
		if((res-(c+mult))<0){
			mult++;
			res= x*mult;
		}
		else break;
	}
	
	multip = mult - 1;
	res = c + multip;
	
	return res;
}

long long maxAmigo2(long long c1, long long c2, long long x, long long y){
	long long mcmXY = mcm(x,y);
	
	 //antes de res1
	long long multPt1 = res1/mcmXY;
	long long c2Pt1= res1 - c1 -multPt1;
	long long c2Pt2 = c2- c2Pt1;
	//printf("\nAntes de res1\n");
	//printf(" multPt1: %d\n c2Pt1: %d\n c2Pt2: %d\n", multPt1, c2Pt1, c2Pt2);
	
	//después de res1
	long long multAres1 = res1/y;
	long long multDres1 = (c2Pt2)/y;
	if((c2Pt2)%y != 0)
		multDres1++;
	long long res= y*(multDres1+multAres1); //cambio
	//printf("\nDespues de res1\n");
	//printf(" multAres1: %d\n multDres1: %d\n res: %d\n", multAres1, multDres1, res);
	
	while(1){
		if((res-(res1 + c2Pt2 + multDres1)<0)){ //cambio
			multDres1++;
			res= y*(multDres1+multAres1);
		}
		else break;
	}
	
	res = c2Pt2 + res1; //30%
	res = res + res/mcmXY - multPt1;
	//res = c2Pt2 + res1 - multPt1; // AmigosyRegalos
	//res = c2Pt2 + multDres1-1 + res1; //20%
	//printf("res = c2Pt2: %d + mult-1: %d + res1: %d = %d\n", c2Pt2, multDres1-1, res1, res);
	
	return res;
}

long long max(long long a, long long b){
	if(a < b) return b;
	else return a;
}

long long mcm(long long a, long long b) {
    return (a * b) / mcd(a, b);
}

long long mcd(long long a, long long b) {
    long long temporal;//Para no perder b
    while (b != 0) {
        temporal = b;
        b = a % b;
        a = temporal;
    }
    return a;
}
