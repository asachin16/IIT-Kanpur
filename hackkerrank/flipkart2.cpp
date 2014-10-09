#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
int M,N;
int min(int a, int b)
{
	return (a<b)?a:b;
}

int minJumps(int source[], int destination[], int** Array1, int** Array2, int *count)
{   
    if (count[0] > M*N)
	return INT_MAX;
	
	
	
	if(source[0]==destination[0] && source[1]==destination[1]) 
	return 0;
	
	int b = Array1[source[0]][source[1]];
	int ans=INT_MAX,flag=0;
	int k,i,j,final[2],p,q;
	for(k=1;k<=b;k++)
	{
		for(i=source[0]-k;i<=source[0]+k;i++)
		{	
		     j=b-k+source[1];
			if(i>=0 && i<M && j>=0 && j<N && Array2[i][j]==0)
			{ count[0]++;
				
				final[0]=i;
				final[1]=j;
				Array2[i][j]= 1;
				 p = minJumps(final,destination,Array1, Array2, count);
				if(p!=INT_MAX)
				ans= min(ans, 1+p);
				
			}
			 j=source[1]-b+k;
			if(i>=0 && i<M && j>=0 && j<N && Array2[i][j]==0)
			{    count[0]++;
			    final[0]=i;
				final[1]=j;
				Array2[i][j]= 1;
			   q = minJumps(final,destination,Array1, Array2,count);
				if(q!=INT_MAX)
				ans = min(ans, 1+q);
		    }
		}
	}
 return ans;
}

int main()
{
	int i,j, source[2], destination[2], count[1];
	count[0]=0;
	scanf("%d", &M);
	scanf("%d", &N);
	
	int **Array1, **Array2;
    Array1 = new int *[N];
    Array2 = new int *[N];
    for (i=0;i<M;i++)
    Array1[i] = new int[N];
    for (i=0;i<M;i++)
    Array2[i] = new int[N];
    
    
	for (i=0;i<M;i++)
	for (j=0;j<N;j++)
	scanf("%d",&Array1[i][j]);
	
	scanf("%d", &source[0]);
	scanf("%d", &source[1]);
	scanf("%d", &destination[0]);
	scanf("%d", &destination[1]);
	
	for (i=0;i<M;i++)
	for (j=0;j<N;j++)
	Array2[i][j]=0;
	

	
	Array2[source[0]][source[1]]=1;
    int	k = minJumps(source,destination,Array1,Array2, count);
    if (k==INT_MAX)
    printf("LET HER GO");
    else
	printf("%d", k);	
}




