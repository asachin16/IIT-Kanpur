#include<stdio.h>

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
		if (a[i] < a[s])	// a[i] should go to left partition
		{
			l++;	// make left partition larger by incrementing l
			swap(a, l, i);	// move a[i] to left partition
		}

	swap(a, s, l);	// put pivot to its correct position l

	return l;	// return demarcation of partitions
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
	int t,n,count=1,max=0,max1,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int x[n];
		for(i=0;i<n;i++){
			scanf("%d",&x[i]);
		}
		quicksort(x,0,n-1);
		for(i=1;i<=n;i++){
			if(x[i]==x[i-1]&&i<n){
				count++;
			}
			else{
				if(max<count){
					max=count;
					max1=x[i-1];
				}
				count=1;
			}
		}
		printf("%d %d\n",max1,max);
		max=0;
	}
	return 0;
}
