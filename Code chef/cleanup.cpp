#include<stdio.h>

void printArray(int x[],int m){
	int i;
	for(i=0;i<m;i++)
	printf("%d ",x[i]);
}

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
	int t,n,m,i,j,wh[500],l,flag,o,k;
	scanf("%d",&t);
	while(t--){
		flag=0;
		o=0,l=0,k=0;
		scanf("%d",&n);
		scanf("%d",&m);
		int x[m];
		for(j=0;j<m;j++){
			scanf("%d",&x[j]);
		}
		insertionSort(x,m);
		for(j=1;j<=n;j++){
			if(j==x[k]){
				k++;
			}
			else if(flag==0){
				printf("%d ",j);
				flag=1;
			}
			else {
				wh[o]=j;
				flag=0;
				o++;
			}
			
		}
		printf("\n");
		printArray(wh,o);
		printf("\n");
		
	}
	return 0;
}
