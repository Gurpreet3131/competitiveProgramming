#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main()
{
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		int c; scanf("%d",&c);
		mp[c]++;
	}
	map<int, int>::iterator it;
	for(it = mp.begin(); it != mp.end(); ++it)
	{
		int val = it -> second;
		if(val % k != 0)
		{
			cout << it -> first << endl;
			break;
		}
	}
	return 0;
}