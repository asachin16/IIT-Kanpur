#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int t,a,b,m,temp,c,d,cnt;
	unsigned long long n;
	vector<int> C,D;
	vector<int>::iterator it;
	vector<int>::iterator it1;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&a,&b,&m);
		c=a,d=b;
		cnt=1;
		C.push_back(a);
		D.push_back(b);
		it = C.begin();
		it1 = D.begin();
		printf("1\t %d\t %d\n",*it,*it1);
		n=1;
		if(c==0&&d==0){
				printf("-1\n");
				continue;
		}
		else {
		
			while((d!=0 || c!=1)&& !(c==0 && d==0)){
				if(cnt==1){
					n++;
					printf("2.\t%d\t %d\n",*it,*it1);
					//printf("%d\t %d\n",C[n/2],n/2);
					c=(C.front()*C.front()+5*D.front()*D.front())%m;
					d=(C.front()*D.front()*2)%m;
					C.push_back(c);
					D.push_back(d);
					printf("3.\t%d\t %d\t c=%d\n",*it,*it1,c);
					C.erase(C.begin());
					D.erase(D.begin());
					printf("4.\t%d\t %d\n",*it,*it1);
					cnt=0;
				}
				else if(cnt==0){
					n++;
					printf("%d\t %d\n",*it,*it1);
					c=(a*(*it)+5*b*(*it1))%m;
					d=(a*(*it1)+b*(*it))%m;
					C.push_back(c);
					D.push_back(d);
					cnt=1;
					it++,it1++;
				}
				
			}
		}
		//if(n>18446744073709551613)
//		printf("-1\n");
//		else
		if(c==0&&d==0){
			printf("-1\n");
		}
		else
			printf("%lld\n",n);
		C.clear();
		D.clear();
	}
}
