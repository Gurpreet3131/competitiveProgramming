#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int o1=0,e1=0,o2=0,e2=0,a,n;
		scanf("%d",&n);	
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(i%2==0) e1+=a;
			else o1+=a;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(i%2==0) e2+=a;
			else o2+=a;
		}
		long long int ans = min(e1+o2, o1+e2);
		printf("%lld\n",ans);
	}
	return 0;
}