#include <bits/stdc++.h>
using namespace std;

bool comp(const string& a, const string& b)
{
	return a < b;
}
int main()
{
	int n; scanf("%d", &n);	
	string s[n];
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s, s+n, comp);
	for(int i = 0; i < n; i++)
	{
		cout << s[i] << endl;
	}
	return 0;
}