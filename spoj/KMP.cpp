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

void KMPsearch(string pat, string txt)
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
			cout << "String matched at index " << i - j << endl;
			j = lps[j - 1];
		}
		else if(i < n && pat[j] != txt[i])
		{
			if(j != 0) j = lps[j - 1];
			else i++; 

		}
	}

}


int main()
{
	string txt, pat;
	cin >> txt >> pat;
	KMPsearch(pat, txt);
	return 0;
}