#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n,k,min=9999999,r,i;
	scanf("%d %d",&n,&k);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(i=0;i<=n-k;i++){
			r=a[i+k-1]-a[i];
			if(min>r){
				min=r;
			}
	}
	printf("%d",min); 
    return 0;
}
