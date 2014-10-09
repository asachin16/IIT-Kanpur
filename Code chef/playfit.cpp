#include<stdio.h>

int main(){
	int t,n,i,j,min;
	int max=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int g[n];
		scanf("%d",&g[0]);
		min=g[0];
		i=1;
		j=1;
		while(j<n){
			scanf("%d",&g[i]);
			if(g[i]<min){
				min=g[i];
				i--;
			}
			else{
				if(max<g[i]-min)
				max=g[i]-min;
			}
			i++;
			j++;
		}
		if(max>0){
			printf("%d\n",max);
		}
		else{
			printf("UNFIT\n");
		}
		max=0;
	}
	return 0;
}
