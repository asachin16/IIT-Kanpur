#include<stdio.h>
#include<math.h>
int check_prime(int a)
{
   int c;
 
   for ( c = 2 ; c <= (int)sqrt(a) ; c++ )
   { 
      if ( a%c == 0 )
	 return 0;
   }
   if ( c == a )
      return 1;
}

int main(){
	int t,n,count,i;
	scanf("%d",&t);
	while(t--){
		count=1;
		scanf("%d",&n);
		i=n-1;
		while(i>0){
			if(i==1 && count==1){
				printf("ALICE\n");
				break;
			}
			else if(i==2 && count==0){
				printf("ALICE\n");
					break;
			}
			else if(i==2 && count==1){
				printf("BOB\n");
					break;
			}
			else if(check_prime(i)&& count==1){
				n=n-i;
				i=n-1;
				count=0;
				continue;
			}
			else if(check_prime(i)&& count==0){
				n=n-i;
				i=n-1;
				count=1;
				continue;
			}
			i--;
		}
		
	}
}
