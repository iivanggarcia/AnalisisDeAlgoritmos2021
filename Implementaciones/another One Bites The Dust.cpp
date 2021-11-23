#include <iostream>

using namespace std;

int main(){
	unsigned int a,b,c,res;
	
	cin>>a>>b>>c;
	if(a==b)
		res = 2*c + a + b;
	else if(a<b)
		res = 2*c + a + a+1;
	else if(b<a)
		res = 2*c + b + b+1;
	cout<<res;
	return 0;
}
