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
void printArray(int x[],int m){
	int i;
	for(i=0;i<m;i++)
	printf("%d \n",x[i]);
}
int main(){
	int j;
		int x[5];
		for(j=0;j<5;j++)
			scanf("%d",&x[j]);
		quicksort(x,0,5);
		printArray(x,5);
		
}
