#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
long long int s[10000001];
long long int minPrime[10000001]={0};
long long int sf(long long int n)
{
	if(s[n]==0)
	{	
		long long int tempn=n;
		s[n]=1;		
		long long int j=minPrime[tempn];		
		long long int count=0;	
		while(tempn%j==0)
		{		
			count++;				
			tempn/=j;
		}	
		long double pp,b=(1.0/(j+1));
		pp=pow(j,(2*count))/(j+1);
		pp=pp*j; 
		pp+=b;				
		s[n]*=ceil(pp);	
		if(s[tempn]!=0)
		{	
			s[n]*=s[tempn];			
		}
		else 
		{				
			s[n]*=sf(tempn);
		}	
	}
	return s[n];
}
int main()
{		
	s[1]=1;	s[0]=1,minPrime[1]=1;
	for(long long int i=2;i<3163;++i) 
	{
	    if(minPrime[i]==0) 
		{ 	        
			for(long long int j=i*i;j<10000001;j+=i) 
			{
	            if(minPrime[j]==0) 
				{
	                minPrime[j]=i;
	            }
	        }
	    }
	}
	for (long long int i=2;i<=10000001;++i) 
	{
	    if(minPrime[i]==0) 
		{ 
	        minPrime[i]=i;
			s[i]=i*(i-1)+1;
	    }
	}
	int t; scanf("%d",&t);
	while(t>0)
	{
		long long int n; scanf("%lld",&n);
		if(s[n]==0)
		{
			s[n]=sf(n);
		}
	    printf("%lld\n",s[n]);  
		t--;	
	}
	return 0;
}
