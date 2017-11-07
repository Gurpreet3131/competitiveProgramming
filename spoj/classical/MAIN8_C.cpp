#include <bits/stdc++.h>
using namespace std;
long long int maxval = 0, a[50001];
int n, k;

void binarySearch(int l, int r)
{
	if(l <= r)
	{
		int mid = (l + r) / 2, ct = 0;
		for(int i = n - 1; i >= 0; i--)
		{
			ct += a[i] / mid;
		}
		if(ct < k) r = mid - 1;
		else
		{
			if(mid > maxval) maxval = mid;
			l = mid + 1;
		}
		binarySearch(l, r);
	}
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i = 0; i < n; i++) scanf("%lld",&a[i]);
		sort(a,a+n);
		maxval = 0;
		int l = 1, r = a[n - 1];
		binarySearch(l, r);
		printf("%lld\n",maxval);
	}
	return 0;
}