#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main() 
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		int n,r,count=0;
		int x[151]={0},y[151]={0},z[151]={0};
		scanf("%d%d",&n,&r);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
		}
		if(n<3)
		{
			if(n==1) count=0;
			else if(n==2)
			{
				if(x[0]*x[1]>0 || y[0]*y[1]>0 || z[0]*z[1]>0)
				{
					count=0;
				}
				else count=1;
			}
		}
		else
		{
			int cx1=0,cx2=0,cy1=0,cy2=0,cz1=0,cz2=0;			
			for(int i=0;i<n;i++)
			{
				if(x[i]>=r) cx1++;
				if(x[i]<=(-r)) cx2++;
				if(y[i]>=r) cy1++;
				if(y[i]<=(-r)) cy2++;
				if(z[i]>=r) cz1++;
				if(z[i]<=(-r)) cz2++;			
			}
			int cx,cy,cz;
			cx=min(cx1,cx2);
			cy=min(cy1,cy2);
			cz=min(cz1,cz2);
			count=min(min(cx,cy),cz);
		}
  		printf("%d\n",count);
	    t--;
	}
	return 0;
}  
