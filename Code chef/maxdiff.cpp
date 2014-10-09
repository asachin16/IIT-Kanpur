#include<stdio.h>

int max(int x,int y){
	if(x>y) return x;
	else return y;
} 
int mod(int x,int y){
	if(x>y) return x-y;
	else return y-x;
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
	int t,n,k,sum1,sum2,sum3,sum4,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		sum1=0;
		sum2=0;
		sum3=0;
		sum4=0;
		int x[n];
		for(i=0;i<n;i++){
			scanf("%d",&x[i]);
		}
		quicksort(x,0,n-1);
		for(i=0;i<n;i++){
			if(i<k){
				sum1=sum1+x[i];
				sum3=sum3+x[n-1-i];
			}
			else if(i>=k){
				sum2=sum2+x[i];
				sum4=sum4+x[n-1-i];
			}
		}
		printf("%d\n",max(mod(sum1,sum2),mod(sum3,sum4)));
	}
	return 0;
}
