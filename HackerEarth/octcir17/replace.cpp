#include <bits/stdc++.h>
using namespace std;
const int size = 500005;
int arr[size];
int bsize, buckets, n;
//int bcount[750][size];
int **bcount;


void setcount()
{
	for(int i = 0; i <= buckets; i++)
	{
		int ind = i * bsize;
		for(int j = 1; j <= bsize; j++)
		{
			ind = i * bsize + j;
			if(ind > n) break;
			bcount[i][arr[ind]]++;
		}
		if(ind > n) break;
	}
}

int main()
{
	int q;
	scanf("%d%d",&n, &q);
	for(int i = 1; i <= n; i++) scanf("%d",&arr[i]);
	bsize = sqrt(n);
	buckets = n / bsize;
	if(n % bsize == 0) buckets--; 
	buckets++;
	bcount = new int*[buckets + 1]; 
	for(int i = 0; i <= buckets + 1; i++)
		bcount[i] = new int[n + 1];

	setcount();
	while(q--)
	{

		int type, a, b, x, y; scanf("%d%d%d%d",&type,&a,&b, &x);
	
		int bstart = a / bsize, bend = b / bsize;
		if(a % bsize == 0) bstart--;
		if(b % bsize == 0) bend--;

		if(type == 1)
		{
			scanf("%d",&y);
			for(int i = bstart; i <= bend; i++)
			{
				if(bcount[i][x] == 0) continue;
				int ind = i * bsize;
				for(int j = 1; j <= bsize; j++)
				{
					int ind = i * bsize + j;
					if(ind < a) continue;
					if(ind > b || ind > n) break;
					if(arr[ind] == x)
					{
						arr[ind] = y;
						bcount[i][x]--; bcount[i][y]++;
					}
				}
				if(ind > b || ind > n) break;
			}
		}
		else
		{
			int ct = 0;
			for(int i = 1; i <= bsize; i++)
			{
				int ind = bsize * bstart + i;
				if(ind < a) continue;
				else if(ind > b || ind > n) break;
				if(arr[ind] == x) ct++;
			}
			if(bstart < bend)
			{
				for(int i = 1; i <= bsize; i++)
				{
					int ind = bsize * bend + i;
					if(ind < a) continue;
					else if(ind > b || ind > n) break;
					if(arr[ind] == x) ct++;
				}	
			}
			for(int i = bstart + 1; i <= bend - 1; i++)
			{
				ct += bcount[i][x];
			}
			printf("%d\n", ct);
		}
	}
	return 0;
}