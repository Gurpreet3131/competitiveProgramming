#include <bits/stdc++.h>
using namespace std;
vector < vector<pair<int,long long int> > > ad;
vector<int, pair<int,long long int> > vec;
int n,m,t;	
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<5001;i++) ad[i].push_back(vec);

	int maxnode[5001]={0},tt[5001]={0};
	for(int i=0;i<n;i++)
	{
		int u,v; long long ti;
		scanf("%d%d",&u,&v);
		cin>>ti;
		ad[v].push_back(make_pair(u,ti));
	}
	maxnode[n]=0; tt[n]=0;
	queue<int> q;
	q.push(n);
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		for(int i=0;i<ad[node].size();i++
		{
			int adnode = ad[node][i].first;
			long long int tempt = ad[node][i].second;
			

		}		
	}

	return 0;
}