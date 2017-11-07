// incomplete

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		string s,t;
		int win = 1;
		cin>>s>>t;
		int sc[26] = {0}, tc[26] = {0};
		for(int i=0;i<s.length();i++)
		{
			sc[s[i] - 'a']++;
			tc[t[i] - 'a']++;
		}
		if(s.length() == 1) win = 2;
		else 
		{
			
		}

		if(win == 1) printf("A\n");
		else printf("B\n");
	}
	return 0;	
}