#include <bits/stdc++.h>
using namespace std;
int maxval = 0, a[100001];
int n, k;

void binarySearch(int l, int r)
{
	if(l <= r)
	{
		int mid = (l + r) / 2, ct = 1;
		int prev = a[0];
		for(int i = 1; i < n; i++)
		{
			if(a[i] - prev >= mid)
			{
				ct++;
				prev = a[i];
				if(ct == k) break;
			}
		}
		if(ct == k)
		{
			l = mid + 1;
			if(mid > maxval) maxval = mid;
		} 
		else r = mid - 1;
		binarySearch(l, r);
	}
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i = 0; i < n; i++) 
			scanf("%d",&a[i]);
		sort(a,a+n);
		maxval = 0;
		int l = 0, r = a[n - 1];
		binarySearch(l, r);
		printf("%d\n",maxval);
	}
	return 0;
}