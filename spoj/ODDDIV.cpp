#include <bits/stdc++.h>
using namespace std;
const int size = 1000001;
typedef long long int lli;
vector<vector<lli> >fac;
vector<lli> row;

int numfact(int n)
{
	int fact = 1;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			int ct = 0;
			while(n%i == 0)
				n/=i, ct++;
			fact *= (2 * ct + 1);
		}
	}
	if(n > 1) fact *= 3;
	return fact;
}

int main()
{
	for(int i = 0; i <= 10000; i++) fac.push_back(row);
	for(long long int i = 1; i <= 100000; i++)
	{
		int k = numfact(i);
		fac[k].push_back(i*i);
	}
	int t; cin >> t;
	while(t--)
	{
		long long int k, l, h; 
		cin >> k >> l >> h;
		//for(int i = 0; i < fac[k].size(); i++)
		{
		//	cout << fac[k][i] << " ";
		}
		//cout << endl;
		int up = upper_bound(fac[k].begin(), fac[k].end(), h) - fac[k].begin();
		int low = lower_bound(fac[k].begin(), fac[k].end(), l) - fac[k].begin();
		//cout << up << " " << fac[k][up] << endl;
		//cout << low << " " << fac[k][low] << endl;
		cout << up - low << endl;
	}
	return 0;
}