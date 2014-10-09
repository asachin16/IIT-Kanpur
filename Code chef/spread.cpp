#include<stdio.h>

int main(){
	int n,m,c,u,v,k,i,p;
	char d;
	scanf("%d %d %d",&n,&m,&c);
	int x[n];
	for(i=0;i<n;i++){
		x[i]=c;
	}
	while(m--){
		getchar();
		d=getchar();
		if(d=='S'){
			scanf("%d %d %d",&u,&v,&k);
			for(i=u-1;i<v;i++){
				x[i]=x[i]+k;
			}
		}
		else if(d=='Q'){
			scanf("%d",&p);
			printf("%d\n",x[p-1]);
		}
	}
}
