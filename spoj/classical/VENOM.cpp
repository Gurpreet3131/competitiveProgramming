#include <bits/stdc++.h>
using namespace std;
long long int h, p, a;
int minn = 1e7;
void binarySearch(long long int l, long long int r)
{
	if(l <= r)
	{
		long long int mid = (l + r) / 2;
		long long int val = h - (((mid + 1) * mid * p) / 2) + ((mid - 1) * a);
		//cout << mid << " " << val << " " << minn << endl;
		if(val <= 0)
		{
			if(mid < minn) minn = mid;
			r = mid - 1;
		}
		else l = mid + 1;
		binarySearch(l, r);
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		scanf("%lld%lld%lld", &h, &p, &a);
		long long int l = 1, r = 1e6;
		minn = 1e7;
		binarySearch(l, r);
		printf("%d\n", minn * 2 - 1);
	}
	return 0;
}