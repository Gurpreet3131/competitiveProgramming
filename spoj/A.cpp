#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, k; cin >> n >> k;
		int ct = 0;
		for(int i = 0; i < n; i++)
		{
			int a; cin >> a;
			a+=k;
			if(a % 7 == 0) ct++;
		}
		cout << ct << endl;
	}
	return 0;
}