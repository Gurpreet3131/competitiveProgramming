#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		priority_queue<int, vector<int>, greater<int> > entry;
		priority_queue<int, vector<int>, greater<int> > ex;

		for(int i = 0; i < n; i++)
		{
			int in, out; cin >> in >> out;
			entry.push(in); ex.push(out);
		}
		int ct = 0, mx = 0;
		while(!entry.empty())
		{
			int in = entry.top(), out = ex.top();
			if(in < out)
			{
				ct++; entry.pop();
			}
			else if(in > out)
			{
				ct--; ex.pop();
			}
			else
			{
				entry.pop(); ex.pop();
			}
			if(ct > mx) mx = ct;
		}
		cout << mx << endl;
	}
	return 0;
}