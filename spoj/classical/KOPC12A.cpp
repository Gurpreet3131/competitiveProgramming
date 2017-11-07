#include <bits/stdc++.h>
using namespace std;
long long int a[10001], cost[10001];
long long int mincost = INT_MAX;
int n;
long long int costfind(int long long h)
{
	long long int c = 0;
	for(int i = 0; i < n; i++)
	{
		c += fabs(a[i] - h) * cost[i];
	}
	return c;
}

void ternary(int l, int r)
{
	if(l <= r)
	{
		long long int mid1 = (2 * l + r) / 3;
		long long int mid2 = (l + 2 * r) / 3;
		long long int c1 = costfind(mid1);
		long long int c2 = costfind(mid2);
		//cout << mid1 << " " << mid2 << endl;
		//cout << c1 << " " << c2 << endl;
		if(min(c1, c2) < mincost) mincost = min(c1, c2);
		if(c1 < c2) r = mid2 - 1;
		else if(c1 > c2) l = mid1 + 1;
		else l = mid1 + 1, r = mid2 - 1;

		ternary(l, r);
	}
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i = 0; i < n; i++)
		{
			scanf("%lld",&cost[i]);
		}
		int l = 0, r = 10001;
		mincost = 1e18;
		ternary(l, r);
		printf("%lld\n",mincost);
	}
	return 0;
}