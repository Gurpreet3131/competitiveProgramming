#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, p;
		cin >> n >> p;
		int easy = 0, hard = 0;
		for(int i = 0; i < n; i++)
		{
			int val; cin >> val;
			if(val >= p/2) easy++;
			else if(val <= p/10) hard++;
		}
		if(easy == 1 && hard == 2) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}