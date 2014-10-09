#include <stdio.h>
int main(){
	int t,n,i,j,min,l;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		l=0;
		int x[n];
		for(j=0;j<n;j++){
			scanf("%d",&x[j]);
		}
		min=x[0];
		for(j=0;j<n;j++){
			if(x[j]<=min){
				l++;
				min=x[j];			
			}
		}
		printf("%d",l);
	}
	return 0;
}
