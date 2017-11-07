#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a,b,c,d,ans=0;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(d<=a) ans=0;
		else 
		{
			long long int dif=c-a,dif2=d-c;
			if(b>=c)
			{
				ans = (c-a)*(dif2+1);
			}
			else
			{
				ans=(b-a+1)*(d-c+1);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}