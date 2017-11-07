#include <bits/stdc++.h>
using namespace std;
char a[101][101];
int o, m, n;
int si, sj, ei, ej, flag = 0;
void bfs()
{
	int visited[m][n] = {0};
	queue<int> qi, qj,qo;
	visited[si][sj] = 1;
	qi.push(si); qj.push(sj); 
	qo.push(o);
	while(!q.empty())
	{
		int si = qi.front(); qi.pop();
		int sj = qj.front(); qj.pop();
		int ox = qo.front(); qo.pop();
		if(ox <= 0) continue;
		for(int i = max(0, si - 1); i < min(si+2, m); i++)
		{
			for(int j = max(0, sj - 1); j < min(sj+2, n); j++)
			{
				if(visited[i][j] == 0)
				{
					if(a[i][j] == 'T')
					{
						flag = 1;
						break;
					}
					else if(a[i][j] == ' ')
					{
						qi.push(i); qj.push(j); qo.push(ox-1);
						visited[i][j] = 1;
					}
				}
			}
			if(flag == 1) break;
		}
		if(flag == 1) break;
	}
}
int main()
{
	int t; cin >> t;
	while(t--)
	{	
		scanf("%d%d%d", &o, &m, &n);
		flag = 0;
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cin >> a[i][j];
				if(a[i][j] == 'S') si = i, sj = j;
				if(a[i][j] == 'T') ei = i, ej = j;
			}
		}
		bfs();
		if(flag == 1) cout << "Possible\n";
		else cout << "Impossible\n";
	}
	return 0;
}