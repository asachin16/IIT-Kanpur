#include<stdio.h>
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
	int t,n,i,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int x[n];
		for(i=0;i<n;i++){
			scanf("%d",&x[i]);
			if(i==1){
				k=gcd(x[0],x[1]);
			}
			else if(i>1){
				k=gcd(k,x[i]);
			}
		}
		for(i=0;i<n;i++){
			printf("%d ",x[i]/k);
		}
		printf("\n");
	}
	return 0;
}
