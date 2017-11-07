#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	char s[405][405];
	while(t--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
		{
			scanf("%s",s[i]);
		}
		int ct=0;
		for(int i=0;i<m;i++)
		{
			for(int j=n-1;j>=0;j--)
			{
				if(s[i][j] == '0')
				{
					ct++; 
					for(int k=j;k>=0;k--)
					{
						if(s[i][k]=='1') s[i][k]='0';
						else s[i][k]='1';
					}
					for(int k=i;k<m;k++)
					{
						if(s[k][j]=='1') s[k][j]='0';
						else s[k][j]='1';
					}		
					s[i][j]='1';
				}
			}
		}
		printf("%d\n",ct);
	}
	return 0;
}