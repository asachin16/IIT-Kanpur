#include <stdio.h>
int main(){
	int t,n,i,j,min,l;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		l=0;
		int x[n];
		scanf("%d",&x[0]);
		min=x[0];
		l++;
		for(j=1;j<n;j++){
			scanf("%d",&x[j]);
			if(x[j]<=min){
				l++;
				min=x[j];			
			}
		}
		printf("%d\n",l);
	}
	return 0;
}
