#include <bits/stdc++.h>
using namespace std;

void computeLps(string pat, int m, int lps[])
{
	lps[0] = 0;
	int i = 1, len = 0;
	while(i < m)
	{
		if(pat[i] == pat[len])
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
	int k;
	while(1)
	{
		cin >> k;
		string s;
		cin >> s;
		int n = s.length();
		if(k == -1 && s[0] == '*') break;
		int lps[n];
		computeLps(s, n, lps);
		k -= lps[n - 1];
		if(k <= 0) cout << "0\n";
		else 
		{
			int val = n - lps[n - 1];
			int ans = k / val;
			cout << ans << endl;
		}
		
	}
	return 0;
}