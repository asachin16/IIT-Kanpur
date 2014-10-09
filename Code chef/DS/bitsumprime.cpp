#include <stdio.h>
#include<math.h>

int isprime(long long int n){
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0){
			break;
		}
	}
	if(i<=sqrt(n)){
		return 0;
	}
	else{
		return 1;
	}
}

int main(){
	long long int n;
	long long int count=0;
	scanf("%lld",&n);
	while(n>=1){
		count+=n%2;
		n=n/2;
	}
	printf("%d\n",isprime(count));
}
