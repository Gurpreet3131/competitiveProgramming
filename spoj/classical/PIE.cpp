//wrong

#include <bits/stdc++.h>
using namespace std;
const int size = 101;
int a[size];
int main()
{
	int t; scanf("%d", &t);
	double pi = 3.14159;
	while(t--)
	{
		int n; double f;
		scanf("%d%lf",&n, &f); f += 1.0;
		double totalvol = 0;
		long long int sum = 0;
		for(int i = 0; i < n; i++)
		{
			long long int r; scanf("%lld", &r);
			sum += r*r;
		}
		totalvol = sum * pi;
		double ans = totalvol / f;
		printf("%.4lf\n",ans);
	}
	return 0;
}      