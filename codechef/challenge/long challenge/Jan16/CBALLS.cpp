#include<iostream>
#include<stdio.h>
#include<math.h>
#define mod 1000000007
using namespace std;
int main()
{
	int t; scanf("%d",&t);
    long long int b[10001],prime[700],p[10001]={0};
	int index=0;	
	for(int i=2;i<5001;i++)
	{
		if(p[i]==0) 
		{
			prime[index]=i;
			index++;
			for(int j=2;i*j<10001;j++)
			{
				p[i*j]=1;
			}	
		}	
	}
 	while(t>0)
	{
		int n;
		scanf("%d",&n);
		long long int change=0,count=0,count2=0;
    	for(int i=0;i<n;i++)
		{
			scanf("%lld",&b[i]);
			if(i==0) 
			{
				if(b[i]==1) 
				{
					b[i]++;
					count++;
				}
			}			
			else
			{
				if(b[i]<b[i-1])
				{
					count+=(b[i-1]-b[i]);
					b[i]=b[i-1];
				}
				if(b[i]%b[0]!=0) change=1; 
			}
		}
		count2=1000000007;		
		if(change==1)
		{
			for(int i=0;i<index;i++)
			{
				long long int tempcount=0,f=0;
				for(int j=0;j<n;j++)
				{
					if(b[j]%prime[i]!=0)
					{
						f=b[j]/prime[i];
						f=(prime[i])*(f+1);
						f=f-b[j];
					}			
					else f=0;		
					tempcount+=f;
					if(tempcount>count2) break;
				}
				if(tempcount<count2) count2=tempcount;
			}		
			count=count+count2;
		}		
		printf("%lld\n",count);
		t--;	
	}
	return 0;
}
