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

void doubleInsertionSort(float x[],float y[],int m){
	int i,j;
	float min;
	for(i=0;i<m;i++){
		for(j=i;j>=0;j--){
			if(x[j]<x[j-1]){
				min=x[j];
				x[j]=x[j-1];
				x[j-1]=min;
				min=y[j];
				y[j]=y[j-1];
				y[j-1]=min;
			}
		}
	}
}

int main(){
	int n,i,j,m,l,count;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		int x[m];
		for(j=0;j<m;j++){
			scanf("%d",&x[j]);
			x[j]=4*x[j];
		}
		scanf("%d",&l);
		float y[l],z[l];
		for(j=0;j<l;j++){
			scanf("%f",&y[j]);
			
			scanf("%f",&z[j]);
			printf("%f\t%f",y[j],z[j]);
			y[j]=2*3.14*y[j];
			z[j]=2*3.14*z[j];
		}
		insertionSort(x,m);
		doubleInsertionSort(z,y,l);
		j=0;
		for(i=0;i<m;i++){
			while(j<l){
				if(x[i]>z[i]){
					if(x[i]<)
				}
			}
		}
		printf("\n%d",count);
	}
}
