#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tri[101][101];
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n; scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				scanf("%d",&tri[i][j]);
			}
		}
		for(int i=n-2;i>=0;i--)
		{
			for(int j=0;j<=i;j++)
			{
				tri[i][j]+=max(tri[i+1][j],tri[i+1][j+1]);
			}
		}
		printf("%d\n",tri[0][0]);
		t--;
	}
	return 0;
}