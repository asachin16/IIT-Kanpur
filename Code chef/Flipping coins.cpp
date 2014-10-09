#include <stdio.h>
int main(){
	int n,q;
	int k=0,j,i,e,f,g;
	
	scanf ("%d",&n);
	scanf ("%d",&q);
	 int a[n];
	while(q--)
	{
		scanf("%d %d %d",&e,&f,&g);
		if (e){
			for(j=f;j<=g;j++){
				if(a[j]==1) k++;
			}
			printf("%d",k);
			k=0;
		}
		else{
		
			for(j=f;j<=g;j++)
			if(a[j]){
				a[j]=0;
			}
			else {
				a[j]=1;
			}
		}		
	}
	return 0;
}
