#include <bits/stdc++.h>
using namespace std;
struct st
{
	int x;
	int y;
	int r;
	int eaten;
};
int main()
{
	int t; scanf("%d",&t);
	st star[1005];
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&star[i].x,&star[i].y,&star[i].r,&star[i].eaten);
		}
		int px,py,ct=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&px,&py);
			for(int j=0;j<n;j++)
			{
				if(star[j].eaten==1)
				{
					int x,y,r;
					x = star[j].x; y = star[j].y;
					r = star[j].r;
					int val = (px-x)*(px-x)+(py-y)*(py-y);
					if( val <= (r*r))
					{
						ct++; break;
					}
				}
			}
		}

		printf("%d\n",ct);
	}
	return 0;
}