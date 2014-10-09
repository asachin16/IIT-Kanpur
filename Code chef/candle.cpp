#include<stdio.h>

int main(){
	int t,x[10],min=10,i;
	unsigned int mina=10,minb=0;
	scanf("%d",&t);
	while(t--){
		min=10,mina=10;
		scanf("%d",&x[0]);
		for(i=1;i<10;i++){
			scanf("%d",&x[i]);
			if(x[i]<mina){
				mina=x[i];
				min=i;
			}
		}
		if(x[0]<mina){
			mina=x[0];
				min=0;
		}
		if(mina==x[0]){
			for(i=1;i<10;i++){
				if(x[i]!=0){
					minb=i;
					break;
				}
				
			}
		}
		if(min==0){
			switch (mina){
				case 0: printf("%u\n",minb*10); break;
				case 1: printf("%u\n",minb*100); break;
				case 2: printf("%u\n",minb*1000); break;
				case 3: printf("%u\n",minb*10000); break;
				case 4: printf("%u\n",minb*100000); break;
				case 5: printf("%u\n",minb*1000000); break;
				case 6: printf("%u\n",minb*10000000); break;
				case 7: printf("%u\n",minb*100000000); break;
				case 8: printf("%u\n",minb*1000000000); break;
			}
		}
		else{
		
			switch (mina){
				case 0: printf("%u\n",min); break;
				case 1: printf("%u\n",min*10+min); break;
				case 2: printf("%u\n",min*100+min*10+min); break;
				case 3: printf("%u\n",min*1000+min*100+min*10+min); break;
				case 4: printf("%u\n",min*10000+min*1000+min*100+min*10+min); break;
				case 5: printf("%u\n",min*100000+min*10000+min*1000+min*100+min*10+min); break;
				case 6: printf("%u\n",min*1000000+min*100000+min*10000+min*1000+min*100+min*10+min); break;
				case 7: printf("%u\n",min*10000000+min*1000000+min*100000+min*10000+min*1000+min*100+min*10+min); break;
				case 8: printf("%u\n",min*100000000+min*10000000+min*1000000+min*100000+min*10000+min*1000+min*100+min*10+min); break;
			}
		}
	}
	return 0;
}
