#include<stdio.h>

int split ( int a[ ], int lower, int upper )
{
	int i, p, q, t ;

	p = lower + 1 ;
	q = upper ;
	i = a[lower] ;

	while ( q >= p )
	{
		while ( a[p] < i )
			p++ ;

		while ( a[q] > i )
			q-- ;

		if ( q > p )
		{
			t = a[p] ;
			a[p] = a[q] ;
			a[q] = t ;
		}
	}

	t = a[lower] ;
	a[lower] = a[q] ;
	a[q] = t ;

	return q ;
}

void quicksort ( int a[ ], int lower, int upper )
{
	int i ;
	if ( upper > lower )
	{
		i = split ( a, lower, upper ) ;
		quicksort ( a, lower, i - 1 ) ;
		quicksort ( a, i + 1, upper ) ;
	}
}

int main(){
	int n,i,j,k,l=0;
	scanf("%d",&n);
	while(n!=0){
		int x[n];
		for(i=0;i<n;i++){
			scanf("%d",&x[i]);
		}
		quicksort(x,0,n);
		for(i=n-1;i>=2;i--){
			for(j=i-1;j>=1;j--){
				for(k=0;k<=j-1;k--){
					if(x[i]<=x[j]+x[k]){
						continue;
					}
					else{
						l=l+j-k;
						break;
					}
				}
			}
		}
		printf("%d\n",l);
		l=0;
		scanf("%d",&n);
	}
}
