#include<stdio.h>

void printArray(int x[],int m){
	int i;
	for(i=0;i<m;i++)
	printf("%d \n",x[i]);
}
void bubbleSort(int x[],int m){
	int i,j,min;
	for(i=m;i>=0;i--){
		for(j=0;j<i-1;j++){
			if(x[j+1]<x[j]){
				min=x[j+1];
				x[j+1]=x[j];
				x[j]=min;
				
			}
		}
	}
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
void swap(int a[], int i, int j)	// interchange a[i] and a[j]
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int partition(int a[], int s, int e)	// partition a[s] to a[e]
{
	int l;	// l denotes last element of left partition
	int i;

	swap(a, s, (s + e) / 2);	// move pivot from middle to 0
	l = s;	// set size of left partition to 0

	for (i = s + 1; i <= e; i++)	// examine all elements
		if (a[i] > a[s])	// a[i] should go to left partition
		{
			l++;	// make left partition larger by incrementing l
			swap(a, l, i);	// move a[i] to left partition
		}

	swap(a, s, l);	

	return l;	
}

void quicksort(int a[], int s, int e)	// sort a[s] to a[e]
{
	int l;

	if (s >= e)	// array contains 0 or 1 element
		return;	// array is already sorted

	l = partition(a, s, e);	// partition

	quicksort(a, s, l - 1);	// sort left partition
	quicksort(a, l + 1, e);	// sort right partition
}


int main(){
	int n,i,j,m;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		int x[m];
		for(j=0;j<m;j++){
			scanf("%d",&x[j]);
		}
		quicksort(x,0,m-1);
		printArray(x,m);
		
	}
	return 0;
}
