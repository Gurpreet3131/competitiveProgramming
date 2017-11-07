#include<bits/stdc++.h>
#define mod 1000000007
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
int main()
{
	int t;
	long long int a[100001]={0},b[100001]={0}; 
	scanf("%d",&t);
	while(t>0)
	{
		int n;
		long long int sum=0,k,maxmag=0;
		scanf("%d%lld",&n,&k);
		for(int i=0;i<n;i++) scanf("%lld",&a[i]);
		for(int i=0;i<n;i++) scanf("%lld",&b[i]);
		for(int i=0;i<n;i++)
		{
			long long int m=fabs(b[i]);
			if(maxmag<m)
			{
				maxmag=m; 
			}
			sum+=a[i]*b[i];
		}
		sum+=k*maxmag;
		printf("%lld\n",sum);
		t--;
	}	
	return 0;    
}
