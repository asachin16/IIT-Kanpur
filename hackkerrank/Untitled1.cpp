#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,n,c,m,total,ans,remain_wrap;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&c,&m);
        ans=n/c;
        total=ans+ans/m;
        remain_wrap=ans%m+ans/m;
        while(m<=remain_wrap){
            total=total+remain_wrap/m;
            remain_wrap=remain_wrap/m+remain_wrap%m;
        }
        printf("%d\n",total);
	}
    return 0;
}

