#include <bits/stdc++.h>
using namespace std;
const int size = 50001;
long long int d[size], h[size], wid[size], len[size];
long long int vol; 
double level = 1e8;
int n;

int findoverflow(double wl)
{
	double totalvol = 0;
	for(int i = 0; i < n; i++)
	{
		if(d[i] + h[i] <= wl) totalvol += h[i] * wid[i] * len[i];
		else if(d[i] >= wl) totalvol += 0;
		else 
		{
			double hh = wl - d[i];
			totalvol += hh * wid[i] * len[i];
		}
	}
	//cout << vol << " " << totalvol << endl;
	if(vol > totalvol) return 1;
	else return 0;
}

void binarySearch(double l, double r)
{
	if(l < r - 0.0000001)
	{
		double mid = (l + r) / 2;
		//cout << l << " " << r << endl;
		//cout << "mid =  " << mid << endl;
		int overf = findoverflow(mid);
		//cout << "overf = " << overf << endl;
		if(overf == 1) l = mid;
		else
		{
			level = min(mid, level);
			r = mid;
		}
		binarySearch(l, r);
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		scanf("%d", &n);
		long long int totalvol = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%lld%lld%lld%lld",&d[i],&h[i],&wid[i], &len[i]);
			totalvol += h[i] * wid[i] * len[i];
		}
		scanf("%lld", &vol);
		level = 1e8;
		if(vol > totalvol)
		{
			printf("OVERFLOW\n");
		}
		else
		{
			double l = 0.0, r = 1e7;
			binarySearch(l, r);
			//if(level >= 1e8) printf("OVERFLOW\n");
			printf("%.2lf\n", level);
		}
	}
	return 0;
}