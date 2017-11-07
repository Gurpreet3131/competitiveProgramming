//TLE
#include <bits/stdc++.h>
using namespace std;
string s[200001];
int maxind = 0;

int strcomp(string first, string second)
{
	int flen = first.length(), slen = second.length();
	int len = min(flen, slen);
	int cur = 0, flag = 0;

	for(int i = 0; i < len; i++)
	{
		if(flen <= slen)
		{
			if(first[i] == second[cur]) cur++;
			else if(first[i] < second[cur])
			{
				flag = -1; break;
			}
			else
			{
				flag = 1; break;
			}
		}
		else
		{
			//cout << second[i] << " " << first[cur] << endl;
			if(second[i] == first[cur]) cur++;
			else if(first[cur] < second[i])
			{
				flag = -1; break;
			}
			else 
			{
				flag = 1; break;
			}
		}
	}
	//cout << cur << endl;
	//cout << flag << endl;
	if(flag == 0)
	{
		if(flen < slen) flag = -1;
		else if(flen > slen) flag = 1;
	}
	return flag;
}
void binarySearch(int l, int r, string temp)
{
	while(l <= r)
	{
		int mid = (l + r) / 2;
		//cout << s[mid] << " " << temp << endl;
		int val = strcomp(s[mid], temp);
		//cout << mid << " " << val << endl;
		if(val <= 0)
		{
			if(mid > maxind) maxind = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
}

int main()
{
	int n, q; scanf("%d%d",&n,&q);
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s, s + n);
	//for(int i = 0; i < n; i++) cout << s[i] << endl;
	while(q--)
	{
		string temp;
		cin >> temp;
		int l = 0, r = n - 1;
		maxind = -1;
		binarySearch(l, r, temp);
		int ans = maxind + 1;
		printf("%d\n", ans);
	}
	return 0;
}