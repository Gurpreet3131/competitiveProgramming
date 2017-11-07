#include <bits/stdc++.h>
using namespace std;
int visited[21] = {0};
int n, mini = n;
int x[21] = {0};

void bfs()
{
	queue<int> q,ct;
	q.push(0); ct.push(0);
	while(!q.empty())
	{
		int ind = q.front(); q.pop();
		int score = ct.front(); ct.pop();
//		cout << ind << " " << score <<endl;
		if(ind == n && score < mini) mini = score;

		if(ind == n || score > mini) continue;

		if(ind + 1 <= n && score < mini) 
		{
			q.push(ind+1); ct.push(score + 1);
		}
		if(ind + x[ind] <= n && ind + x[ind] >=0)
		{
			q.push(ind + x[ind]); ct.push(score+1);
		} 
	}
}
int main()
{
	int t; cin >> t;
	while(t--)
	{	
		scanf("%d", &n);
		mini = n;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &x[i]);
		}
		bfs();
		cout << mini << endl;
	}
	return 0;
}