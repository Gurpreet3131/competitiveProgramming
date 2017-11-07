#include <bits/stdc++.h>
using namespace std;
int si = -1, sj = -1, ei, ej;
char a[21][21];
int m, n;
bool bfs()
{
	int visited[21][21] = {0};
	queue<int> iq, jq;
	iq.push(si); jq.push(sj);
	visited[si][sj] = 1;
	while(!iq.empty())
	{
		int nodei = iq.front(), nodej = jq.front();
		iq.pop(); jq.pop(); 
		//cout << nodei << " " << nodej << endl;
		if(nodej + 1 < n && a[nodei][nodej+1] == '.' && visited[nodei][nodej+1] == 0)
		{
			iq.push(nodei); jq.push(nodej+1); 
			visited[nodei][nodej+1] = 1; 
			if(nodei == ei && nodej+1 == ej) return true;
		}
		if(nodej - 1 >= 0 && a[nodei][nodej-1] == '.' && visited[nodei][nodej-1] == 0)
		{
			iq.push(nodei); jq.push(nodej-1); 
			visited[nodei][nodej-1] = 1; 
			if(nodei == ei && nodej-1 == ej) return true;
		}
		if(nodei + 1 < m && a[nodei+1][nodej] == '.' && visited[nodei+1][nodej] == 0)
		{
			iq.push(nodei+1); jq.push(nodej); 
			visited[nodei+1][nodej] = 1; 
			if(nodei+1 == ei && nodej == ej) return true;
		}
		if(nodei - 1 >=0 && a[nodei-1][nodej] == '.' && visited[nodei-1][nodej] == 0)
		{
			iq.push(nodei-1); jq.push(nodej); 
			visited[nodei-1][nodej] = 1; 
			if(nodei-1 == ei && nodej == ej) return true;
		}
	}

	return false;
}
int main()
{
	int t; cin >> t;
	while(t--)
	{	
		scanf("%d%d", &m, &n);
		int ct = 0;
		si = -1; sj = -1; 
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cin >> a[i][j];
				if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
				{
					if(a[i][j] == '.') 
					{
						ct++;
						if(si < 0) si = i, sj = j;
						else ei = i, ej = j;
					}
				} 
			}
		}
		//cout << ct << endl;
		if(ct == 2)
		{
			bool flag = bfs();
			if(flag) cout << "valid\n";
			else cout << "invalid\n"; 
		}
		else
		{
			cout << "invalid\n";
		} 
	}
	return 0;
}