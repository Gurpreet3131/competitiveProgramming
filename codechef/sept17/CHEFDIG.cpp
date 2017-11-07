#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d", &t);
	string s;
	while(t--)
	{
		int ct[10] = {0};
		string ans = "";
		cin >> s;		
		for(int i = 0; i < s.length(); i++)
		{
			ct[s[i] - '0']++;
		}
		for(int i = 65; i < 91; i++)
		{
			int l = i/10, r = i%10;
			if(l == r)
			{
				if(ct[l] > 1) ans += (char)(i);
			}
			else
			{
				if(ct[l] >= 1 && ct[r] >= 1)
					ans += (char)(i); 
			}
		}
		cout << ans << endl;
	}
	return 0;
}