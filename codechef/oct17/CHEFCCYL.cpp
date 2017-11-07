#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int> > > interdist;
vector<pair<int, int> > distrow;
int n;
const int nn = 100001;
int v1[nn][2], bigw[nn];
int bigdistc[nn] = {0}, bigdista[nn] = {0};
int dist[nn] = {0}, distc[nn] = {0};
int dista[nn] = {0};

int cycle[nn];

void findmindist(int node, int m, int cycleno)
{
	int ct = 1, u = node, v = node % m + 1;
	distc[u] = 0; dista[u] = 0; dist[u] = 0;
	while(ct < m)
	{
		int distval = cycle[u];
		distc[v] = distc[u] + distval;
		u = v; v = v % m + 1;
		ct++;
	}
	ct = 1; u = node; v = ((node % m - 1) + m) % m;
	if(v == 0) v = m;
	while(ct < m)
	{
		int distval = cycle[v];
		dista[v] = dista[u] + distval;
		u = v; v = ((v % m - 1) + m) % m;
		if(v == 0) v = m;
		ct++;
	}
	interdist.push_back(distrow);
	interdist[cycleno].push_back(make_pair(0,1));
	for(int i = 1; i <=m; i++)
	{
		dist[i] = min(dista[i], distc[i]);
		int dir = dista[i] < distc[i]? -1 : 1;
		interdist[cycleno].push_back(make_pair(distc[i], dista[i]));
	}
}	

int getdistance(int cycle, int node1, int node2)
{
	int tempdist = 0;
	int mini = interdist[cycle][node1].first + interdist[cycle][node2].second;
	mini = min(mini, interdist[cycle][node1].second + interdist[cycle][node2].first);
	mini = min(mini, (int)fabs(interdist[cycle][node1].second - interdist[cycle][node2].second));
	return mini;
}

void findcyclemindist()
{
	int u = 0, v = (u+1) % n;
	int ct = 1;
	while(ct < n)
	{
		int distval = bigw[u]; // u - v
		int tempdist = getdistance(u, v1[u][0], v1[u][1]);
		if(u > 0) distval += tempdist;
		bigdistc[v] = bigdistc[u] + distval;

		u = v; v = (v+1) % n;
		ct++;
	}
	ct = 1; u = 0; v = (u - 1 + n) % n;
	while(ct < n)
	{
		int distval = bigw[v];
		int tempdist = getdistance(u, v1[u][0], v1[u][1]);
		if(u > 0) distval += tempdist;
		bigdista[v] = bigdista[u] + distval;
		u = v; v = (u - 1 + n) % n;
		ct++;
	}
}


int findanswer(int v2, int c2, int v3, int c3)
{
	int distc = 0, dista = 0;
	
	int tempdist = getdistance(c2, v1[c2][0], v2);
	distc += tempdist;
	if(c3 > c2) 
	{
		distc+= bigdistc[c3] - bigdistc[c2];
		tempdist = getdistance(c2, v1[c2][1], v1[c2][0]);
		if(c2 > 0) distc -= tempdist;	
	}
	else
	{
		distc+= bigdista[c2] + bigdistc[c3];
		tempdist = getdistance(0, v1[0][0], v1[0][1]);
		if(c3 > 0) distc += tempdist;
	}
	distc += getdistance(c3, v1[c3][1], v3);
	dista += getdistance(c2, v2, v1[c2][1]); 
	if(c3 < c2 && c3 > 0) 
	{
		dista += bigdistc[c2] - bigdistc[c3];
		tempdist = getdistance(c3, v1[c3][0], v1[c3][1]);
		if(c3 > 0) dista -= tempdist; 
	}
	else if(c3 < c2 && c3 == 0) dista += bigdistc[c2];
	else
	{
		dista += bigdista[c3] + bigdistc[c2];
		if(c2 > 0) dista += getdistance(0, v1[0][1], v1[0][0]); 
	} 
	dista += getdistance(c3, v3, v1[c3][0]);
	return min(dista, distc);
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int q;
		scanf("%d%d", &n, &q);
		interdist.clear();
		for(int i = 0; i < n; i++)
		{
			int m; scanf("%d",&m);
			for(int j =  1; j <= m; j++) scanf("%d", &cycle[j]);
			findmindist(1, m, i);
		}
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d%d",&v1[i][0], &v1[(i+1)%n][1], &bigw[i]);
		}
		findcyclemindist();		
		while(q--)
		{
			int v2, c2, v3, c3;
			scanf("%d%d%d%d", &v2, &c2, &v3, &c3);
			int answer = findanswer(v2,c2 - 1,v3,c3 - 1);
			printf("%d\n",answer);
		}
	}
	return 0;
}