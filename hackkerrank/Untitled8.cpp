#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    return !(n & (n - 1));
}
int check_prime(int a)
{
   int c;
 
   for ( c = 2 ; c <= sqrt(a) ; c++ )
   { 
      if ( a%c == 0 )
	 return 0;
   }
   if ( c>=sqrt(a) )
      return 1;
}

int main() {
	int t,a,b,m,temp,c,d,j,e,g,cnt3=0,cnt;
	unsigned long long n,f=1,cnt2;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&a,&b,&m);
		c=a,d=b,cnt=0,cnt2=0,cnt3=0;
		n=1;
		e=a;
		
		if(c==0&&d==0){
				
				printf("-1\n");
				continue;
		}
		else {
			while((d!=0 || c!=1)&& !(c==0 && d==0)){
				//printf("1\tc=%d \td=%d\n",c,d);
				if(c==0){
					e=(5*d*d)%m;
					c=e;
					d=0;
					n=2*n;
					f=n;
				}
				else if(d==0){
					if(c!=cnt){
						
						c=(c*e)%m;
						if(cnt3==0){
							cnt=c;
							cnt3=1;
						}
						d=0;
						n=n+f;
					}
					else{
						c=0;d=0;
						break;
					}
				}
				else if (cnt2<1000000){
					temp=(a*c+5*b*d)%m;
					d=(a*d+b*c)%m;
					c=temp;
					n++;
					e=c;
					f=n;
					cnt2++;
				}
				else{
					c=0,d=0;
					break;
				}
			}
		}
		if(c==0&&d==0){
			printf("-1\n");
		}
		else
			printf("%lld\n",n);
	}
}
