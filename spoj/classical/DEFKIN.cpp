#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b)
{
	if(a > b) return a;
	else return b;
}
int main()
{
	int t; cin >> t;
	while(t--)
	{
		long long int w, h, n;
		cin >> w >> h >> n;
		long long int x[n + 2], y[n + 2];
		x[0] = 0; y[0] = 0;
		n++; x[n] = w+1; y[n] = h+1;
		for(int i = 1; i <= n - 1; i++)
		{
			scanf("%lld%lld",&x[i], &y[i]);
		}
		sort(x,x+n); sort(y, y+n);
		long long int mx = 0, my = 0, dif = 0;
		for(int i = 0; i < n; i++)
		{
			mx = max(mx, x[i+1] - x[i] - 1);
			my = max(my, y[i+1] - y[i] - 1);
		}
		if(n == 0) mx = w, my = h;
		long long int ans = mx * my;
		printf("%lld\n", ans);
	}
	
	return 0;
}