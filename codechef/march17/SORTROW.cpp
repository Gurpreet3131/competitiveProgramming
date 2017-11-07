#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; scanf("%d",&n);
	int a[n][n],b[n][n], pos[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			b[i][j] = a[i][j];
			pos[i][a[i][j]] = j;
		}
		sort(a[i], a[i]+n);
	}
	long long int s1=0, s2=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			s1 += fabs(j - pos[i][a[i][j]]);
			s2+= fabs(n-1-pos[i][a[i][j]]);
		}
	}
	for(int i=0;i<n;i++)
	{
		//if(s1<s2)
		{
			for(int j=0;j<n;j++)
			{
		//		printf("%d ",a[i][j]);
			}
		}
		//else
		{
			for(int j=n-1;j>=0;j--)
			{
				printf("%d ",a[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}