#include <stdio.h>

int isgreater(int a,int b){
	if(a>b) return a;
	else return b;
}
long long int fact(int a){
	if (a==1 || a==0) return 1;
	else return a*fact(a-1);
}

long long int fact2(int a,int b){
	if (a==b) return 1;
	else return a*fact2(a-1,b);
}
long long int C(int a,int b){
	int c = isgreater(a-b,b);
	int d;
	if (c==b) d=a-b;
	else d=b;
	long long int f =fact2(a,c);
	return f/fact(d);
}
int main(){
	int t,z;
	int n,k,a;
	scanf("%d %d",&t,&z);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&n,&k);
		a=n-k;
		printf("%lld",C(a+k-1,k-1));		
	}
	return 0;
}
