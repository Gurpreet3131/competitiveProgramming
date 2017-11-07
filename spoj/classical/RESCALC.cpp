#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int n,numc; 
		scanf("%d",&n);
		int points[n+1]={0};
		for(int i=1;i<=n;i++)
		{
			int count[7]={0};
			scanf("%d",&numc);
			for(int j=1;j<=numc;j++)
			{
				int type; scanf("%d",&type);
				count[type]++;
			}
			points[i]=numc;
			while(true)
			{
				int diftype=0,min=10000;
				for(int i=1;i<=6;i++)
				{
					if(count[i]>0) diftype++;
					if(count[i]>0 && count[i]<min) min=count[i];
				}
				if(diftype<4) break;
				else 
				{
					points[i]+=min;
					for(int i=1;i<=6;i++) 
					{
						//if(count[i]>0)
						{

						}
					}
				}
			}
		}
	}
	return 0;
}