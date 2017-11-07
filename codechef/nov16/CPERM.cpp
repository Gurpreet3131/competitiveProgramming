#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
	int t;
	scanf("%d",&t);
	long long int p[35]={0};
	p[0]=1; p[1]=2;
	for(int i=2;i<34;i++) 
	{
		p[i] = p[i-1]*p[i-1];
		if(p[i]>=mod) p[i]%=mod;
	}
	
	while(t--)
	{
		int n;
		scanf("%d",&n);
		n--;	
		int temp = n,dig=1;
		long long int sum = 1;
		if(n<2)
		{
			printf("0\n");
			continue;	
		}
		while(temp>0)
		{
			if(temp%2==1)
			{
				sum*=p[dig];
				if(sum>=mod) sum%=mod;
			}
			dig++; temp/=2;
		}
		sum+= mod-2;
		sum%=mod;
		printf("%lld\n",sum);
	}	
	return 0;
}