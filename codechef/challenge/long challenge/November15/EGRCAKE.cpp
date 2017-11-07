//without using hcf
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int m,n;
        long long int count=0;
		scanf("%d%d",&n,&m);
       	 	//if(m>(n/2)) m=n-m;
		if(m==0 && n==1) printf("Yes\n");
		else if(m==0) printf("No 1\n");
        else if(m==1) printf("Yes\n");
		else
		{
	  		if(n%m==0) 
            {
                count=n/m;                
                printf("No %lld\n",count);
            }
            else
            {                
                int tempm=m;                
                for(int i=sqrt(n);i>0;i--)
                {                  
                    if(m%i==0 && n%i==0)
                    {                        
                        m=i; break;                   
                    }    
                }  
                if(m==1) printf("Yes\n");
                else 
                {
                    count=n/m;                
                    printf("No %lld\n",count);
                }
            }
            
		}
		t--;	
	}
	return 0;
}
