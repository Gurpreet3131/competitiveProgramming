#include <bits/stdc++.h>
using namespace std;
int p[1000001]={0};
int main()
{
	p[0]=0; p[1]=0;
	for(int i=2;i<1000001;i++)
	{
		if(p[i]==0)
		{
			p[i]=1;
			for(int j=2;i*j<1000001;j++)
			{
				p[i*j]++;
			}
		}
	}
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,k,ct=0;
		scanf("%d%d",&n,&k);
		if(p[n]==k) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}