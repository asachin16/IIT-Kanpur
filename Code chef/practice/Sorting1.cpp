#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int a[],int n){
	int i,j,min,index;
	for(i=0;i<n;i++){
		min=a[i];
		for(j=i+1;j<n;j++){
			if(min>a[j]){
				min=a[j];
				index=j;
			}
		}
		a[index]=a[i];
		a[i]=min;
	}
}
void bubbleSort(int a[],int n){
	int i,j,temp;
	for(i=n-1;i>0;i--){
		for(j=0;j<i;j++){
			//printf("%d\n",j);
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void insertionSort(int a[],int n){
	int i,j=0,x=a[1],max;
	for(i=1;i<n;i++){
		
		x=a[i];
		for(j=i-1;j>=-1;j--){
			if(a[j]>x&&j!=-1){
			//	printf("%d\n",j);
				a[j+1]=a[j];
			//	printf("%d\n",a[j+1]);
			}
			else{
				a[j+1]=x;
				break;
			}	
		}
	}
}

void printArray(int a[],int n){
	int i=10;
	for(i=0;i<10;i++){
		printf("%d\n",a[i]);
	}
}

int main(){
	int a[10];
	int i=9;
	srand(time(NULL));
	while(i>=0){
		a[i]=rand()%100;
		i--;
	}
		printArray(a,10);
	insertionSort(a,10);
	printf("\n");
	printArray(a,10);
	
	
}
