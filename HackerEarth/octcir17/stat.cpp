#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, mod;
	cin >> n >> a >> mod;
	long long int ans = 0;
	if(n == 1) ans = 0;
	else if(n == 2)	ans = a % mod;
	else if(a == 1) ans = (n - 1) % mod;
	else if(n == 3)
	{
		ans = (a % mod) * ((a - 1) % mod);
		ans = (ans * 4) % mod;
	}
	cout << ans << endl;
	return 0;
}