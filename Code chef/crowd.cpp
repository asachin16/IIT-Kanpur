#include<stdio.h>

int main(){
	int t,count,count1,i,j,m;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		count1=1,count=0;
		scanf("%d",&m);
		for(j=m;j>=3;j--){
			count=count+count1;
			count1++;
		}
		printf("%d",count);
	}
}
