#include <bits/stdc++.h>
using namespace std;

void computeLps(string s, int m, int lps[])
{
	lps[0] = 0;
	int i = 1, len = 0;

	while(i < m)
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
	string s;
	while(1)
	{
		cin >> s;
		if(s[0] == '*') break;
		int n = s.length();
		int lps[n] = {0};
		computeLps(s, n, lps);
		int sub = n - lps[n - 1], ans = 1;
		if(n % sub == 0) ans = n / sub;

		cout << ans << endl;		
	}
	return 0;
}