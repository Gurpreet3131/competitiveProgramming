#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	int ti[100003];
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&ti[i]);
		}
		long long int tt = 0;
		for(int i=2;i<=n;i++)
		{
			if(tt<ti[i]) tt = ti[i];
		}
		printf("%lld\n",tt+1);
	}
	return 0;
}