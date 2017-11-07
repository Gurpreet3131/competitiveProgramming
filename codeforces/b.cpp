#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s; cin >> s;
	int len = s.length();
	int ans = 0;
	int act[len], bct[len];
	for(int i = 0; i < len; i++)
	{
		if(i == 0)
		{
			act[i] = 0; bct[i] = 0;
			if(s[i] == 'a') act[i] = 1;
			else bct[i] = 1;
			continue;
		}
		if(s[i] == 'a') act[i] = act[i - 1] + 1, bct[i] = bct[i - 1];
		else act[i] = act[i - 1], bct[i] = bct[i - 1] + 1;
	}

	int temp, tempmax = 0;
	for(int i = 0; i < len; i++)
	{
		int ct = 0;
		if(s[i] == 'b')
		{
			for(int j = i; j < len; j++)
			{
				if(s[j] == 'b')
				{
					ct++;
					temp = act[i] + ct + act[len - 1] - act[j];
					if(temp > tempmax) tempmax = temp;
				}
			}
		}
	}

	ans = max(tempmax, max(act[len - 1], bct[len - 1]));
	cout << ans << endl;
	return 0;
}