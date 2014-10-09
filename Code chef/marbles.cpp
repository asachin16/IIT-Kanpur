#include <stdio.h>
int main(){
	int n,q;
	int k=0,j,i,e,f,g;
	
	scanf ("%d",&n);
	scanf ("%d",&q);
	 int a[n];
	for(i=0;i<q;i++)
	{
		scanf("%d %d %d",&e,&f,&g);
		if (e==0){
			for(j=f;j<=g;j++)
			if(a[j]==0){
				a[j]=1;
			}
			else {
				a[j]=0;
			}
		}
		else if(e=1){
			for(j=f;j<=g;j++){
				if(a[j]==1) k++;
			}
			printf("%d",k);
		}		
	}
	return 0;
} 
