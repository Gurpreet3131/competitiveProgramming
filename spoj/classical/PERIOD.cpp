#include <bits/stdc++.h>
using namespace std;

void computeLps(string s, int n, int lps[])
{
	lps[0] = 0;
	int i = 1, len = 0;
	while(i < n)
	{
		if(s[i] == s[len])
		{
			lps[i] = len + 1;
			len++; i++;
		}
		else
		{
			if(len != 0) len = lps[len - 1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main()
{
	int t; cin >> t;
	for(int tt = 1; tt <= t; tt++)
	{
		int n; cin >> n;
		string s;
		cin >> s;
		int lps[n];
		computeLps(s, n, lps);
		cout << "Test case #"<< tt << endl;
		for(int i = 2; i <= n; i++)
		{
			int ans = 1;
			int sub = i - lps[i - 1];
			if(i % sub == 0) ans = i / sub;
			if(ans > 1) cout << i << " " << ans << endl;
		}
	}
	return 0;
}