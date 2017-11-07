#include <bits/stdc++.h>
using namespace std;
const int size = 300009;
vector<pair<int, int> > xy;
int segmax[4 * size];
int li, ri;

void buildsegtree(int s, int e, int nodenum)
{
	//segmax[nodenum] = INT_MIN;
	if(s == e)
	{
		segmax[nodenum] = xy[s].second;
	}
	else
	{
		int mid = (s + e) / 2;
		buildsegtree(s, mid, nodenum * 2);
		buildsegtree(mid + 1, e, nodenum * 2 + 1);
		segmax[nodenum] = max(segmax[nodenum*2], segmax[nodenum * 2 + 1]);
	}
}

int query(int l, int r, int s, int e, int nodenum)
{
	if(s > r || e < l) return INT_MIN;
	else if(s >= l && e <= r) return segmax[nodenum];
	else
	{
		int mid = (s + e) / 2;
		return max(query(l, r, s, mid, nodenum*2), query(l, r, mid + 1, e, nodenum * 2 + 1));
	}
}
void binarySearch(int l, int r, int val)
{
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(xy[mid].first < val)
		{
			ri = max(mid, ri);
			l = mid + 1;
		}
		else r = mid - 1;
	}
}

void binarySearch2(int l, int r, int val)
{
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(xy[mid].first > val)
		{
			li = min(mid, li);
			r = mid - 1;
		}
		else l = mid + 1;
	}
}

int main()
{
	int n, q;
	cin >> n >> q;
	xy.push_back(make_pair(INT_MIN, INT_MIN));
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d",&x, &y);
		xy.push_back(make_pair(x, y));
	}
	sort(xy.begin(), xy.end());

	buildsegtree(1, n, 1);
	
	while(q--)
	{
		int si, sj, fi, fj;
		scanf("%d%d%d%d",&si, &sj, &fi, &fj);
		long long int cost = 0;
		if(si == fi && sj == fj) cost = 0;
		else
		{
			cost += fabs(sj - fj);
			sj = max(sj, fj);
			fj = max(sj, fj);
			int mini = min(si, fi);
			int maxi = max(si, fi);
			si = mini; fi = maxi;
			cost += fabs(fi - si);
			if(si < fi - 1)
			{
				li = INT_MAX; ri = -1;
				binarySearch(1, n, fi);
				binarySearch2(1, n, si);
				int maxval = INT_MIN;
				//cout << li << " " << ri << endl;
				if(li <= ri)
				{
					maxval = query(li, ri, 1, n, 1);
				}
				if(maxval >= sj)
				{
					cost += 2 * fabs(maxval - sj) + 2;
				}
			}
		}
		printf("%lld\n",cost);
	}
	return 0;
}