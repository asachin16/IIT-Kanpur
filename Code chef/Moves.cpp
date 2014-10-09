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
	int t,m,c=0,i,j,k;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&m);
		int x[m];
		for(j=0;j<m;j++)
			scanf("%d",&x[j]);
		j=0;
		while(j<m-1){
			quicksort(x,0,m);
			for(j=0;j<m-1;j++){
				if(x[j]==x[j+1]){
					continue;
				}
				else{
					for(k=0;k<m-1;k++){
						x[k]++;
					}
					c++;
					break;
				}
			}
				
		}
		printf("%d",c);
		c=0;
	}
	return 0;
}
