#include <bits/stdc++.h>
using namespace std;
const int size = 1000001;
long long int phi(int n)
{
	long long int result = n;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			while(n % i == 0)
				n /= i;
			result -= result / i;
		}
	}

	if(n > 1) 
		result -= result / n;
	return result;
}
int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		long long int ans = phi(n);
		cout << ans << endl;
	}
	return 0;
}