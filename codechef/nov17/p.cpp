#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct cof
{
	lli a0, a1, a2,a3;
};

lli l = 0, r = 100000;
lli minval[100002];

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n, q;
		scanf("%d",&n);
		vector<cof> v1(n);
		for(int i = 0; i < n; i++)
		{
			scanf("%lld%lld%lld%lld",&v1[i].a0,&v1[i].a1,&v1[i].a2,&v1[i].a3);
		}
		scanf("%d",&q);
		for(lli i = 0; i <= r; i++)
		{
			minval[i] = 1e18 + 1;
			for(int j = 0; j < n; j++)
			{
				lli val = v1[j].a0 + v1[j].a1 * i + v1[j].a2 * (i * i) + v1[j].a3 * (i * i *i);
				if(val < minval[i]) minval[i] = val;
			}
		}
		for(int i = 0; i <= r; i++)
		{
			cout << i << " " << minval[i] << endl;
		}
		q = 0;
		while(q--)
		{
			int x; scanf("%d",&x);
			printf("%lld\n", minval[x]);
		}
	}
	return 0;
}