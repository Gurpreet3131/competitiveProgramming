#include <bits/stdc++.h>
using namespace std;
void getZarr(string s, int n, int z[])
{
	int l = 0, r = 0, k = 0;
	for(int i = 1; i < n; i++)
	{
		if(i > r)
		{
			l = r = i;
			while(r < n && s[r - l] == s[r]) r++;
			z[i] = r - l;
			r--;
		}
		else
		{
			k = i - l;
			if(z[k] < r - i + 1) z[i] = z[k];
			else
			{
				l = i;
				while(r < n && s[r-l] == s[r]) r++;
				z[i] = z[r - l];
				r--;
			}
		}
	}
}

int search(string pat, string txt)
{
	string s = pat + "$" + txt;
	int n = s.length(), m = pat.length(), ct = 0;
	int z[n];
	getZarr(s, n, z);
	for(int i = 0; i < n; i++)
	{
		if(z[i] == m) ct++;
	}
	return ct;
}

int main()
{
	string pat, txt;
	cin >> pat >> txt;
	int ct = search(pat, txt);
	printf("%d\n",ct);
}