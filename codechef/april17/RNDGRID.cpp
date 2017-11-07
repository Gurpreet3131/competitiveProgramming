#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	char a[1002][1002];
	while(t--)
	{
		for(int i=0;i<1002;i++)
		{
			for(int j=0;j<1002;j++)
			{
				a[i][j] = '#';
			}
		}
		int l,n;
		string s;
		scanf("%d%d",&l,&n);
		cin>>s;
		long long int x = 0;
		int flag = 1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				//scanf("%c",&a[i][j]);
				cin>>a[i][j];
				if(a[i][j] == '#') flag = 0;
			}
		}
		if(flag == 1)
		{
			int maxu = 0, maxd = 0, maxr = 0, maxl = 0;
			int up =0, down = 0, left = 0, right = 0;
			for(int i=0;i<l;i++)
			{
				if(s[i] == 'R')
				{
					right++; left--;
					if(right > maxr) maxr = right;
				}
				else if(s[i] == 'L')
				{
					right--; left++;
					if(left > maxl) maxl = left;
				}
				if(s[i] == 'U')
				{
					up++; down--;
					if(up > maxu) maxu = up;
				}
				if(s[i] == 'D')
				{
					down++; up--;
					if(down > maxd) maxd = down;
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(a[i][j] == '.')
					{
						if(i )
					}
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					int ct = 0;
					if(a[i][j] == '#') continue;
					int ci = i, cj = j;
					for(int k = 0; k<l;k++)
					{
						if(s[k] == 'R') cj++;
						else if(s[k] == 'L') cj--;
						else if(s[k] == 'U') ci--;
						else if(s[k] == 'D') ci++;

						if(a[ci][cj] == '#') break;
						ct++;
					}
					//cout<<ct<<endl;
					if(ct>0) x = x^ct;
				}
			}
		}
		printf("%lld\n",x);
	}
	return 0;
}