#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d", &t);
	while(t--)
	{
		int n, m, c; scanf("%d%d%d",&n, &m, &c);
		int co[2502] = {0};
		for(int i = 0; i < c; i++)
		{
			scanf("%d", &co[i]);
		}
		int j = 0, i = 0;
		int a[51][51] = {0};
		for(int ii = 0; ii < c; ii++)
		{
			while(co[ii]--)
			{	
				if(i%2 == 0)
				{
					a[i][j] = ii+1; 
					j++;
				}
				else
				{
					a[i][j] = ii+1;
					j--;
				}
				if(j >= m || j < 0)
				{
					i++; 
					if(i%2 == 0) j = 0;
					else j = m - 1;
				}
			}
		}
		for(int i = 0; i < n;i++)
		{
			for(int j = 0; j < m; j++)
			{
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		
	}
}