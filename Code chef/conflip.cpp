#include<stdio.h>

int main(){
	int t,I,n,q,g;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&g);
		while(g--){
			scanf("%d %d %d",&I,&n,&q);
			if(I==q){
				printf("%d\n",n/2);
			}
			else if(n%2==0){
				printf("%d\n",n/2);
			}
			else{
				printf("%d\n",n/2+1);
			}
		}
	}
	return 0;
}
