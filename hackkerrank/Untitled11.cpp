#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t,a,b,m;
	unsigned long long n,f=1,cnt,cnt2,temp,c,d,e;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&a,&b,&m);
		c=a,d=b,cnt2=0;
		n=1;
		e=a,f=1;
		
		if(c==0&&d==0){
				
				printf("-1\n");
				continue;
		}
		else {
			while((d!=0 || c!=1)&& !(c==0 && d==0)&&(cnt2<1000000)){
				if(c==0){
					c=(5*d*d)%m;
					e=c;
					d=0;
					n=2*n;
					f=n;
				}
				else if(d==0){
						c=(c*e)%m;
						n=n+f;
				}
				else {
					temp=(a*c+5*b*d)%m;
					d=(a*d+b*c)%m;
					c=temp;
					n++;
					e=c;
					f=n;
					cnt2++;
				}
			}
		}
		if((c==0&&d==0)||(cnt2>=1000000)){
			printf("-1\n");
		}
		else
			printf("%lld\n",n);
	}
}
