#include <bits/stdc++.h>
using namespace std;
int n;
long long int ct = 0;
//unordered_map<string, long long int> mp; //faster 0.65
map<string, long long int> mp;
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

int main()
{
	cin >> n;
	string s;
	int len;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &len);
		cin >> s;
		int lps[len];
		computeLps(s, len, lps);
		int period = len, sub = len - lps[len - 1];
		if(lps[len - 1] > 0 && len % sub == 0) period = sub;
		string temp="";
		for(int j = 0; j < period; j++) temp+= s[j];

		mp[temp]++;
		long long int val = mp[temp];
		ct -= (val - 1) * (val - 1);
		ct += val * val;
	} 
	printf("%lld\n",ct);
}