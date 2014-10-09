#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N,k,p,q,r,min;
    scanf("%d",&N); scanf("%d",&k);
    int i,A[N],B[N],C[N],D[N],E[N],F[N],G[N];
    for (i=0;i<N;i++) scanf("%d",&A[i]);
    sort(A,A+N);
    
	for (i=1;i<N;i++)
	B[i] = A[i] - A[i-1];
//	for(i=1;i<N-1;i++){
//	printf("%d\t",B[i]);
//}
//printf("\n");
	
	C[0]=0;
	for (i=1;i<k;i++)
	C[0] = C[0]+B[i];
	
	for (i=1;i<N-k;i++)
	C[i] = C[i-1] - B[i] + B[i+k-1];
	
	p = C[0];
	D[0]=p;
	for (i=1;i<k-1;i++)
	{
		
	D[0]= D[0]+p - B[k-i];
	p = p - B[k-i];
}
for (i=1;i<N-k;i++)
D[i] = D[i-1] - (k-1)*B[i]+ C[i];

//for(i=0;i<N-k;i++){
//	printf("%d\t",C[i]);
//}
//printf("\n");
//for(i=0;i<N-k;i++){
//	printf("%d\t",D[i]);
//}

E[0]=0;
	for (i=1;i<k;i++)
	E[0] = E[0]+B[k-i];
	
	for (i=1;i<N-k;i++)
	E[i] = E[i-1] - B[i] + B[i+k-1];
	
		q = E[0];
	F[0]=q;
	for (i=1;i<k-1;i++)
	{
		
	F[0]= F[0]+q - B[i];
	q = q - B[i];
}
for (i=1;i<N-k;i++)
F[i] = F[i-1] + (k-1)*B[i+k-1]- E[i-1];

min = C[0];
r = C[0];
for (i=1;i<k-1;i++)
{
min = min + r - (k-i)*B[i];
r = r - (k-i)* B[i];
}
G[0]=min;
for(i=1;i<N-k;i++)
G[i] = G[i-1] + F[i] - D[i-1];
for(i=0;i<N-k;i++){
	printf("%d\t",G[i]);
}
min=*min_element(G,G+N-k+1);
printf("%d",min);

	return 0;
    
    
}
