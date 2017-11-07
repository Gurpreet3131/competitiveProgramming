#include<iostream>
#include<stdio.h>
#include<math.h>
#define mod 1000000007
using namespace std;
int main()
{
	int t; scanf("%d",&t);
    long long int num[100005];
    long long int p[100003],s[100005];
    p[0]=1;
    for(int i=1;i<100003;i++)
    {
        p[i]=2*p[i-1]; if(p[i]>=mod) p[i]%=mod;
    }
	while(t>0)
	{
		int n;
		scanf("%d",&n);
       	for(int i=0;i<=n;i++)
        {
            scanf("%lld",&num[i]);
			if(i==0)  continue;          
			if(i==1) s[i]=num[i-1];
			else
			{
				s[i]=p[i-2]*num[i-1];
			 	if(s[i]>=mod) s[i]%=mod;
				s[i]=s[i]+s[i-1];
			}
           if(s[i]>=mod) s[i]%=mod;
        }
        long long int sum=0; 
        for(int i=n;i>0;i--)
        {          
            long long int pr=0;            
			pr=p[n+1-i]*num[i];
			if(pr>=mod) pr%=mod;
			pr=pr*s[i];
			if(pr>=mod) pr%=mod;			          	
			sum+=pr; if(sum>=mod) sum%=mod;
        }
        printf("%lld\n",sum);
		t--;	
	}
	return 0;
}
