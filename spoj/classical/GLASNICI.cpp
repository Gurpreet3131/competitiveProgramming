#include <bits/stdc++.h>
using namespace std;
int n, m;
double k, dist[100001];

int postime(double mid)
{
	double start = dist[0] + mid;

	for(int i = 1; i < n; i++)
	{
		if(start + k < dist[i] - mid) return 0;
		else start = min(start + k, dist[i] + mid);
	}
	return 1;
}

double binarySearch(double l, double r)
{
	double mintime = 10000000000;
	while(r - l > 0.0001)
	{
		double mid = (l + r) / 2;
		int pos = postime(mid);
		if(pos == 1)
		{
			if(mid < mintime) mintime = mid;
			r = mid;
		}
		else l = mid;
	}
	return mintime;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%d",&k, &n);
		for(int i = 0; i < n; i++) scanf("%lf",&dist[i]);
		double l = 0, r = 1000000001;
		double ans = binarySearch(l, r);
		printf("%.3lf\n",ans);
	}
	return 0;
}