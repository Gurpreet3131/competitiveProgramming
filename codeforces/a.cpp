#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string m[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
	int ct = 0;
	for(int i = 0; i < 5; i++)
	{
		int len = s.length();
		for(int j = 0; j < len; j++)
		{
			int flag = 0, mct = 0;
			for(int k = 0; k < m[i].length(); k++)
			{
				if(s[j + k] == m[i][k])
				{
					mct++;
				}		
				if(mct == m[i].length())
				{
					flag = 1;
				}
			}
			if(flag == 1) ct++;
		}
	}
	if(ct == 1) printf("YES\n");
	else printf("NO\n");
	return 0;
}