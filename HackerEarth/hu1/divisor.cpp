#include <bits/stdc++.h>
using namespace std;

int a[1000001],ct[1000001],p[1000001];
int main()
{
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ct[a[i]]++;
	}
	for(int i=2;i<1000001;i++)
	{
		if(p[i]==0 && ct[i]>0)
		{
			for(int j=2*i;j<1000001;j+=i)
			{
				if(p[j] == 0) p[j] = i;
			}
		}
	}
	while(m--)
	{
		int ind; scanf("%d",&ind);
		if(p[a[ind]] == 0) printf("-1\n");
		else printf("%d\n",p[a[ind]]);
	}
	return 0;
}