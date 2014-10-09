#include<stdio.h>

int main(){
	int t,x[11],i,k,j,l,count;
	scanf("%d",&t);
	while(t--){
		for(i=0;i<11;i++){
			scanf("%d",&x[i]);
		}
		quicksort(x,0,10);
		scanf("%d",&k);
		n=x[10-k+1];
		for(i=10-k+2;i<11;i++){
			if(x[i]==n){
				j=i;
			}
			else break;
		}
		for(i=10-k;i>0;i--){
			if(x[i]==n){
				l=i;
			}
			else break;
		}
		
		
		
		
	}
}
