#include <bits/stdc++.h>
using namespace std;
int n, m;
long long int a[1000001];
int maxh = 0;
void binarySearch(int l, int r)
{
	if(l <= r)
	{
		int mid = (l + r) / 2;
		long long int sum = 0;
		for(int i = n - 1; i >=0; i--)
		{
			if(a[i] <= mid) break;
			else sum += a[i] - mid;
		}
		if(sum >= m)
		{
			if(mid > maxh) maxh = mid;
			l = mid + 1;
		}
		else r = mid - 1;
		binarySearch(l, r);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++) 
		scanf("%lld",&a[i]);
	sort(a,a+n);
	int l = 0, r = a[n - 1];
	binarySearch(l, r);
	printf("%d\n",maxh);
	return 0;
}