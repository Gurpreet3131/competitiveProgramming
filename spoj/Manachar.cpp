#include <bits/stdc++.h>
using namespace std;
int p[200004];
void longestPalindromeSubstring(string temp)
{
	string s = "#";
	for(int i = 0; i < temp.length(); i++)
	{
		s = s + "$" + temp[i];
	}
	s+= "$@";
	int n = s.length();
	int c = 0, r = 0, center = 0, maxlen = 0;
	for(int i = 1; i < n - 1; i++)
	{
		int iMirror = c - (i - c);

		if(r > i)
		{
			p[i] = min(p[iMirror], r - i);
		}

		// put i as center
		while(s[i + 1 + p[i]] == s[i - 1 - p[i]])
			p[i]++;

		if(i + p[i] > r)
		{
			c = i;
			r = i + p[i];
		}
		if(p[i] > maxlen)
		{
			maxlen = p[i]; center = i;
		}
	}
	printf("%d\n",maxlen);
	for(int i = center - maxlen + 1; i < center + maxlen; i+=2)
	{
		printf("%c",s[i]);
	}
	//cout << temp.substr( (center - 1 - maxlen)/2, maxlen);
	printf("\n");
}

int main()
{
	string s;
	cin >> s;
	longestPalindromeSubstring(s);
	return 0;
}