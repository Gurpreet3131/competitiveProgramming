#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	int a[402][402];
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int curj;
		curj = (n+1)/2;
		
		for(int i=1;i<=n;i++)
		{
			int j = curj, val=1;
			while(true)
			{
				a[i][j++] = val++;
				if(j>n) j=1;
				if(val >n) break;
			}
			curj++;
			if(curj>n) curj=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}	
	return 0;
}