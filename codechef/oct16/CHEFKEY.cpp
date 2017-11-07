#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,m,c,ct=0;
		scanf("%d%d%d",&n,&m,&c);
		for(int i=1;i<=n;i++)
		{
			if(c%i == 0 && c/i<=m) ct++; 
		}
		printf("%d\n",ct);
	}
	return 0;
}