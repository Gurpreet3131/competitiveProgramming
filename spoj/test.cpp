#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int size = 100002;
lli a[101]; 
int main()
{
	int t; cin >> t;
	while(t--)
	{
		lli x, y; cin >> x >> y;
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a+n);
		long long int ans = 0;
		int l = 1, r = n - 2;
		int left = 0, right = n - 1;
		while(l <= r)
		{
			long long int lval = x*(a[l]-a[left]) + y*(a[right] - a[l]);
			long long int rval = x*(a[r]-a[left]) + y*(a[right]-a[r]);
			if(lval <= rval) 
			{
				ans += lval; l++; left++;
			}
			else ans += rval; r--; right--;
		}
		cout << ans << endl;
	}
	return 0;
}