#include<stdio.h>

int main(){
	int t,a,b,c,i,temp,j;
	float maxa;
	scanf("%d",&t);
	while(t--){
		i=0;
		j=0;
		scanf("%d %d %d",&a,&b,&c);
		maxa=a+b/100.0;
		while(!(c>b && a==0)){
			if(c<=b){
				b=b-c;
				temp=b;
				b=a;
				a=temp;
				j++;
				if(maxa<a+b/100.0){
					maxa=a+b/100.0;
					i=j;
				}
			}
			else if(c>b && a>0){
				a=a-1;
				b=b-c+100;
				temp=b;
				b=a;
				a=temp;
				j++;
				if(maxa<a+b/100.0){
					maxa=a+b/100.0;
					i=j;
				}
				
			}
		}
		printf("%d\n",i);
	}
	return 0;
}
