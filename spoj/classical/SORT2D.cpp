#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
	if(a.first == b.first) return a.second > b.second;
	else return a.first < b.first;
}
int main()
{
	int t; scanf("%d", &t);
	while(t--)
	{
		int n; scanf("%d", &n);
		pair<int, int> point[n];
		for(int i = 0; i < n; i++)
		{
			int x, y; scanf("%d%d",&x, &y);
			point[i] = make_pair(x, y);
		}
		sort(point, point+n, comp);
		for(int i = 0; i < n; i++)
		{
			printf("%d %d\n",point[i].first, point[i].second);
		}
	}
	return 0;
}