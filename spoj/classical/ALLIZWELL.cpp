#include <bits/stdc++.h>
using namespace std;
char a[101][101];
string s = "ALLIZZWELL";
int gflag = 0;
int r, c;
int visited[101][101] = {0};
void dfsutil(int si, int sj, int depth)
{
	if(gflag == 1) return;
	visited[si][sj] = 1;
	for(int i = max(0, si - 1); i < min(si+2, r); i++)
	{
		for(int j = max(0, sj - 1); j < min(sj+2, c); j++)
		{
			if(visited[i][j] == 0 && a[i][j] == s[depth])
			{
				//cout << i << " " << j << " " << s[depth] << endl;
				if(depth == 9) gflag = 1;
				if(gflag == 1) break;
				dfsutil(i, j, depth + 1);
				visited[i][j] = 0;				
			}
		}
		if(gflag == 1) break;
	}
}

bool dfs(int si, int sj, int depth)
{
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			visited[i][j] = 0;
	dfsutil(si, sj, depth + 1);
	return gflag;
}
int main()
{
	int t; cin >> t;
	while(t--)
	{	
		gflag = 0;
		scanf("%d%d", &r, &c);
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				cin >> a[i][j];
			}
		}
		int flag = 0;
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				if(a[i][j] == 'A') 
					flag = dfs(i, j, 0); 
				if(flag == 1) break;
			}
			if(flag == 1) break;
		}

		if(flag == 1) cout <<"YES\n";
		else cout << "NO\n";
	}
	return 0;
}