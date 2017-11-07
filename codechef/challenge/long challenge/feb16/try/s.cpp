#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#define mod 1000000007
using namespace std;
int main()
{
	int t; scanf("%d",&t);    	    
	int counti[1000001]={0};
	int countj[1000001]={0};
	int qi[10001]={0},qj[10001]={0};
			
	while(t>0)
	{
        long long int n,m,maxcount=0;
		scanf("%lld%lld",&n,&m);
		//if()
		int a[n][m],maxnum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
		}
		for(int i=0;i<n;i++)
		{									
			int indexi=0;			
			for(int k=0;k<m;k++)
			{
				counti[a[i][k]]++;
				if(counti[a[i][k]]==1) qi[indexi++]=a[i][k];
			}			
			for(int j=0;j<m;j++)
			{
				maxcount=0;
				int indexj=0;				
				for(int k=0;k<n;k++)
				{
					if(k==i) continue;					
					countj[a[k][j]]++;
					if(countj[a[k][j]]==1) qj[indexj++]=a[k][j];						
					if(counti[a[k][j]]+countj[a[k][j]]>maxcount) maxcount=counti[a[k][j]]+countj[a[k][j]];
				}
				if(maxcount>maxnum) maxnum=maxcount;
				for(int l=0;l<indexj;l++)
				{
					countj[qj[l]]=0;
					qj[l]=0;
				}
			}			
			for(int l=0;l<indexi;l++)
			{
				counti[qi[l]]=0;
				qi[l]=0;
			}
		}
		printf("%d\n",maxnum);
		t--;
	}
	return 0;
}
