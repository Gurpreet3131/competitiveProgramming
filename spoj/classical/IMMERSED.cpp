#include <bits/stdc++.h>
using namespace std;
double p, c;
double minn;
double val(double l, double r)
{
	double mid;
	for(int i = 0; i < 100; i++) //50 works too
	{
		mid = (l + r) / 2;
		double ans = mid * pow(mid, c*mid);
		if(ans > p) r = mid;
		else l = mid;
	}
	return mid;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		// nmax = 13
		scanf("%lf%lf",&p, &c);
		//cin >> p >> c;
		double l = 1.0, r = 40.0;
		minn = 100.0;
		//minn = binarySearch(l, r);
		minn = val(l, r);
		//cout << minn << endl;
		printf("%.6lf\n",minn);
	}
	return 0;
}