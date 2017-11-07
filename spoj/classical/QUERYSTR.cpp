#include <bits/stdc++.h>
using namespace std;

int getZarr(string s, int n, int z[])
{
	int l = 0, r = 0, k = 0;
	for(int i = 1; i < n; i++)
	{
		if(i > r)
		{
			l = r = i;
			while(r < n && s[r- l] == s[r]) r++;
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
				while(r < n && s[r -l] == s[r]) r++;
				z[i] = r - l;
				r--;
			}
		}
	}
	z[0] = n;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		string temp = "";
		int n = s.length();
		for(int i = n-1; i>=0; i--) temp+= s[i];
		int z[n];
		getZarr(temp, n, z);
		int q; cin >> q;
		while(q--)
		{
			int ind; scanf("%d",&ind);
			printf("%d\n", z[n - (ind - 1) - 1]);
		}
	}
	return 0;
}