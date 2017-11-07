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
				int diftype=0,minc=10000;
				for(int j=1;j<=6;j++)
				{
					if(count[j]>0) diftype++;
					if(count[j]>0 && count[j]<minc) minc=count[j];
				}
				if(diftype<4) break;
				else 
				{
					if(diftype==4) points[i]+=minc;
					else if(diftype==5) points[i]+=2*minc;
					else if(diftype==6) points[i]+=4*minc;
					for(int j=1;j<=6;j++) 
					{
						count[j]-=minc;
					}
				}
			}
		}
		int max=0,flag=0,index=0;
		for(int i=1;i<=n;i++)
		{
			//cout<<i<<" "<<points[i]<<endl;
			if(points[i]>max) max=points[i],flag=0,index=i;
			else if(points[i]==max) flag=1;
		}
		if(flag==1) printf("tie\n");
		else
		{
			if(index==1) printf("chef\n");
			else printf("%d\n",index);
		}
	}
	return 0;
}