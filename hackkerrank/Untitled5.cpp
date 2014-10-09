#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n,k,r,i,j,l,cnt=0;
	unsigned long long min;
	scanf("%d %d",&n,&k);
	unsigned long long int a[n];
	unsigned long long b[n-k+1];
	unsigned long long sum;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	j=k-1;
	l=k-1;
	b[0]=0;
	while(j>=1){
		b[0]=b[0]+j*(a[l]-a[k-l-1]);
		j=j-2;
		l=l-1;	
	}
	min=b[0];
	sum=0;
	for(i=1;i<k;i++){
			sum=sum+a[i];
	}
	j=k-1;
	for(i=1;i<=n-k;i++){
		b[i]=b[i-1]+j*(a[i+k-1]+a[i-1])-2*sum;
		if(min>b[i]){
			min=b[i];	
		}
		sum=sum-a[i]+a[i+k-1];
	}
	printf("\n%lld",min); 
    return 0;
}
