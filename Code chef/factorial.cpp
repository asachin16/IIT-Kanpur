#include <stdio.h>
 
int Z (int m)
{
    int i=0,j=0,k=0,l=0;
    while(m>4)
    {
        j=0;
        k=m;
        while(k>4)
    	{
    		 if (k%25==0){
	             l=l+2;
	             k=k/25;
	             if(j==0){
	                      m=m-5;
	                      j++;
	            }
	        }
	        else if (k%5==0){
	             l++;
	             k=k/5;
	             if(j==0){
	                      m=m-5;
	                      j++;
	            }
	        }
		    else{
		    	if(j==0){
	                      m--;
	                      j++;
		        }
		      	break;
		      }
		}               
                    
                                     
    }
    return l;
    
}
	 
	 
	int main ()
	{
	    int a,i,n;
	    scanf("%d",&a);
	    for(i=0;i<a;i++){
	    	scanf("%d",&n );                
	    	printf("%d\n",Z(n)); 
		}	
	    return 0;       
	    
	} 
