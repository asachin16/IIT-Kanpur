#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int a[], int i, int j)	// interchange a[i] and a[j]
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int partition(int a[],int b[], int s, int e)	// partition a[s] to a[e]
{
	int l;	// l denotes last element of left partition
	int i;

	swap(a, s, (s + e) / 2);	// move pivot from middle to 0
	swap(b, s, (s + e) / 2);
	l = s;	// set size of left partition to 0

	for (i = s + 1; i <= e; i++)	// examine all elements
		if (a[i] > a[s])	// a[i] should go to left partition
		{
			l++;	// make left partition larger by incrementing l
			swap(a, l, i);	// move a[i] to left partition
			swap(b, l, i);
		}

	swap(a, s, l);	// put pivot to its correct position l
	swap(b, s, l);
	return l;	// return demarcation of partitions
}

void quicksort(int a[],int b[],int s, int e)	// sort a[s] to a[e]
{
	int l;

	if (s >= e)	// array contains 0 or 1 element
		return;	// array is already sorted

	l = partition(a,b, s, e);	// partition

	quicksort(a,b, s, l - 1);	
	quicksort(a,b, l + 1, e);	
}

int main(){
	int n,i,k=0,cnt=1,j,x,y,min,z;
	scanf("%d",&n);
	int t[n],f[n];
	for(i=0;i<n;i++){
		scanf("%d %d",&t[i],&f[i]);	
	}
	int t1[n],f1[n];
	t1[0]=t[0];
	f1[0]=f[0];
	for(i=1;i<n;i++){
		min=-1;
		cnt=1;
		quicksort(t1,f1,0,k);
		for(j=k;j>=0;j--){
			x=t[i]-t1[j]-abs(f1[j]-f[i]);
			if(x>=0&&x>min){
				min=x;
				y=i;
				z=j;
			}
			if(min!=100000){
				f1[z]=f[y];
				t1[z]=t[y];
				cnt=0;
				break;
			}
		}
	}
		if(cnt!=0){
			k++;
			f1[k]=f[i];
			t1[k]=t[i];
			cnt=1;
		}
		
	
	printf("%d\n",k+1);
	
}
