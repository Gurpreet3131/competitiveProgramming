#include <bits/stdc++.h>
using namespace std;
int n, m;
long long int a[10001], b[10001], g[50001];
long long int minsum = 1e18, grace;

long long int calc(int mid)
{
	long long int s = 0;
	for(int i = 0; i < n; i++)
	{
		s += fabs(a[i] - b[i] - g[mid]);
	}
	return s;
}

void ternary(int l, int r)
{
	if(l <= r)
	{
		int mid = (l*2 + r) / 3;
		int mid2 = (l + r*2) / 3;
		long long int sum1 = calc(mid);
		long long int sum2 = calc(mid2);
		//cout << l << " " << r << endl;
		//cout << mid << " " << mid2 << endl;
		//cout << sum1 << " " << sum2 << endl;
		if(min(sum1, sum2) < minsum)
		{
			if(sum1 < minsum) grace = g[mid];
			else if(sum2 < minsum) grace = g[mid2];
			minsum = min(sum1, sum2);
		}
		else if(min(sum1, sum2) == minsum)
		{
			if(sum1 == minsum) grace = min(grace, g[mid]);
			else if(sum2 == minsum) grace = min(grace, g[mid2]);	
			minsum = min(sum1, sum2);
		}
		if(sum1 > sum2) l = mid + 1;
		else if(sum1 < sum2) r = mid2 - 1;

		if(sum1 == sum2)
		{
			ternary(l, mid2 - 1);
			ternary(mid + 1, r);
		}
		else ternary(l, r);

	}
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i++) scanf("%lld",&a[i]);
		for(int i = 0; i < n; i++) scanf("%lld",&b[i]);
		scanf("%d",&m);
		for(int i = 0; i < m; i++) scanf("%lld",&g[i]);
		sort(g,g+m);
		int l = 0, r = m - 1;
		minsum = 1e18; grace = g[n - 1];
		ternary(l, r);	
		printf("%lld\n",grace);
	}
	return 0;
}