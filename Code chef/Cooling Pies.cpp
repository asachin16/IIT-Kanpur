#include <stdio.h>

void insertionSort(int x[],int m){
	int i,j,min;
	for(i=0;i<m;i++){
		for(j=i;j>=0;j--){
			if(x[j]<x[j-1]){
				min=x[j];
				x[j]=x[j-1];
				x[j-1]=min;
			}
		}
	}
}
int main(){
	int t,k=0,i,j,m,count=0,x[30],y[30];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&m);
		for(j=0;j<m;j++){
			scanf("%d",&x[j]);
		}
		for(j=0;j<m;j++){
			scanf("%d",&y[j]);
		}
		printf("\n");
		insertionSort(x,m);
		insertionSort(y,m);
		j=0;
		while(k<m){
			if(x[j]<=y[k]){
				count++;
				k++;
				j++;
			}
			else{
				k++;
			}
		}
		printf("%d",count);
		count=0;
		k=0;	
	}
	return 0;
}
