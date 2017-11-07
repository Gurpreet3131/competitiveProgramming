#include <bits/stdc++.h>
using namespace std;
const int size = 300005;
long long int x[size], p[size];
long long int segmax[4 * size];
long long int segp[4*size];
 
void buildsegtree(int s, int e, int nodenum)
{
	if(s == e)
	{
		segmax[nodenum] = x[s] + p[s];
		segp[nodenum] = p[s];
	}
	else
	{
		int mid = (s + e) / 2;
		buildsegtree(s, mid, nodenum * 2);
		buildsegtree(mid + 1, e, nodenum * 2 + 1);
		segmax[nodenum] = max(segmax[nodenum*2], segmax[nodenum*2+1]);
		segp[nodenum] = max(segp[nodenum*2], segp[nodenum*2+1]);
	}
}
 
void range_update(int l, int r, int s, int e, int nodenum)
{
	if(s > r || e < l) return;
	else if(s >=l && e <= r) 
	{
		segmax[nodenum] = x[s] + p[s];
		segp[nodenum] = p[s];
	}
	else
	{
		int mid = (s + e) / 2;
		range_update(l, r, s, mid, nodenum * 2);
		range_update(l, r, mid + 1, e, nodenum * 2 + 1);
		segmax[nodenum] = max(segmax[nodenum*2], segmax[nodenum*2+1]);
		segp[nodenum] = max(segp[nodenum*2], segp[nodenum*2+1]);
	}
 
}
 
long long int queryp(int l, int r, int s, int e, int nodenum)
{
	if(s > r || e < l) return INT_MIN;
	else if(s >=l && e <= r) return segp[nodenum];
	else
	{
		int mid = (s + e) / 2;
		return max(queryp(l, r, s, mid, nodenum*2), queryp(l, r, mid + 1, e, nodenum*2 + 1));
	}
}
 
long long int query(int l, int r, int s, int e, int nodenum)
{
	if(s > r || e < l) return INT_MIN;
	else if(s >=l && e <= r) return segmax[nodenum];
	else
	{
		int mid = (s + e) / 2;
		return max(query(l, r, s, mid, nodenum*2), query(l, r, mid + 1, e, nodenum*2 + 1));
	}
}
 
int main()
{
	int n, q;
	scanf("%d%d",&n, &q);
	for(int i = 1; i <= n; i++) scanf("%lld",&x[i]);
	for(int i = 1; i <= n; i++) scanf("%lld",&p[i]);
	buildsegtree(1, n, 1);
	while(q--)
	{
 
		int type, a, b; scanf("%d%d%d",&type,&a,&b);
		long long int tempmax = INT_MIN, temp = 0;
		if(type == 1)
		{
			x[a] = b; range_update(a, a, 1, n, 1);
		}
		else if(type == 2) 
		{
			p[a] = b;
			range_update(a, a, 1, n, 1);
		}
		else
		{
			long long int minval = queryp(a, b, 1, n, 1);
			if(minval <= 0)
			{
				tempmax = query(a, b, 1, n, 1);
			}
			else
			{
				for(int i = a; i <= b; i++)
				{
					temp = x[i] + (long long int)min((int)p[i], i - a);
					if(temp > tempmax) tempmax = temp;
				}
			}
			printf("%lld\n", tempmax);
		}
	}
	return 0;
}