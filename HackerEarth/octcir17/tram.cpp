#include <bits/stdc++.h>
using namespace std;
int vis[100001];
vector<int> mpath;

int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	int ct = 0;
	for(int i = 1; i <= m; i++)
	{
		int c, p;
		cin >> c >> p;
		int newm = 0;
		for(int j = 0; j < p; j++)
		{
			int val; cin >> val;
			if(vis[val] == 0 && newm == 0)
			{
				newm = 1;
				mpath.push_back(i);
			}
			vis[val] = 1;
		}
	}
	while(q--)
	{
		int a, b;
		cin >> a >> b;
	}
	cout << mpath.size() << endl;
	for(int i = 0; i < mpath.size(); i++)
	{
		cout << mpath[i] << " ";
	}
	cout << endl;
	return 0;
}