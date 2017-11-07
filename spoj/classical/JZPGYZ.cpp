#include <bits/stdc++.h>
using namespace std;
int n, q;
long long int ct = 0;

void computeLps(string pat, int m, int lps[])
{
	lps[0] = 0;
	int len = 0, i = 1;
	while(i < m)
	{
		if(pat[i] == pat[len])
		{
			lps[i] = len + 1;
			i++; len++;
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

int KMPSearch(string pat, string txt)
{
	int n = txt.length(), m = pat.length();

	int lps[m];
	computeLps(pat, m, lps);
	int i = 0, j = 0;
	while(i < n)
	{
		if(pat[j] == txt[i])
		{
			i++; j++;
		}

		if(j == m)
		{
			return 1;
			j = lps[j - 1];
		}
		else if(i < n && pat[j] != txt[i])
		{
			if(j != 0) j = lps[j - 1];
			else i++; 

		}
	}
	return 0;
}

int main()
{
	cin >> n >> q;
	string s[n];
	for(int i = 0; i < n; i++) cin >> s[i];

	for(int i = 0; i < q; i++)
	{
		string pat; cin >> pat;
		ct = 0;
		for(int j = 0; j < n; j++)
		{
			ct += KMPSearch(pat, s[j]);
		}
		printf("%lld\n",ct);
	}
}