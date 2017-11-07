#include <bits/stdc++.h>
using namespace std;
int ct[26] = {0};
vector<int> alpha;
void allStrings(int n)
{
	string ans = "";
	for(int i = 0; i< n; i++)
		ans += (char)(alpha[0]);

	int flag = 0, i = n - 1;
	while(flag == 0)
	{
		cout << ans << endl;
		i = n - 1;
		while(1)
		{
			ans[i]++;
			if(ans[i] - 'a' > 'z' - 'a') ans[i] = (char)(alpha[0]), i--;
			else if(ct[ans[i] - 'a'] == 0) //the alphabet is not present in the string
			{
				ans[i]++; continue;
			}
			else break;

			if(i < 0)
			{
				flag = 1; break;
			}
 		}
	}
}

int main()
{
	string s = "abc";
	int len = s.length();
	for(int i = 0; i < len; i++)
		ct[s[i] - 'a']++;
	for(int i = 0; i < 26; i++)
	{
		if(ct[i] >= 1) alpha.push_back((i+ 'a'));
	}
	allStrings(len);
	return 0;
}