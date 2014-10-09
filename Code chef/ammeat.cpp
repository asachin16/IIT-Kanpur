#include<stdio.h>
void swap(long long int a[], int i, int j)	// interchange a[i] and a[j]
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int partition(long long int a[], int s, int e)	// partition a[s] to a[e]
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

	swap(a, s, l);	// put pivot to its correct position l

	return l;	// return demarcation of partitions
}

void quicksort(long long int a[], int s, int e)	// sort a[s] to a[e]
{
	int l;

	if (s >= e)	// array contains 0 or 1 element
		return;	// array is already sorted

	l = partition(a, s, e);	// partition

	quicksort(a, s, l - 1);	// sort left partition
	quicksort(a, l + 1, e);	// sort right partition
}
int main(){
	int t,n,i,j;
	long long  m,sum;
	scanf("%d",&t);
	while(t--){
		sum=0;
		j=0;
		scanf("%d %lld",&n,&m);
		long long x[n];
		for(i=0;i<n;i++){
			scanf("%lld",&x[i]);
		}
		quicksort(x,0,n-1);
		for(i=0;i<n;i++){
			sum=sum+x[i];
			if(sum>=m){
				break;
			}
		}
		i=i+1;
		if(sum<m){
			i=-1;
		}
		printf("%d\n",i);
	}
	return 0;
}
