#include<stdio.h>

float series(float n,float m){
	return n+m;
}
float parallel(float n,float m){
	return (n*m)/(n+m);
}
float solve(int n){
	if(n==1) return 1;
	if(n==2) return parallel(series(1,1),1);
	else{
		return parallel(series(1,solve(n-1)),1);
	}	
}
int gcd(int n, int m)
{
	int t;

	for (; 1; ) {

		if (n < m) { /* Swap to make n at least as large as m */
			t = m;
			m = n;
			n = t;
		}

		if (n % m == 0) /* m is the gcd */
			return m;
		else /* replace n by n (mod m) */
			n = n % m;
	}
}


int main(){
	int t,n,m,q;
	int r;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		r=solve(n)*1000000;
		q=gcd(r,1000000);
		printf("%d / %d",(r/q)%m,(1000000/q)%m);
	}
	
}
