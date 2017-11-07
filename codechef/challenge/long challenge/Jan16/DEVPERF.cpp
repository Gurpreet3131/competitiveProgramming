#include<iostream>
#include<stdio.h>
#include<math.h>
#define mod 1000000007
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	int *stari,*starj;
	stari=new int[1000001]; starj=new int[1000001];
 	while(t>0)
	{
		int n,m;
		char h[1001][1001];
		scanf("%d%d",&n,&m);
		long long int mintime=1000000,counts=0; 
		int mini=10000,minj=10000,maxi=0,maxj=0;   	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{	
				cin>>h[i][j];
				if(h[i][j]=='*') 
				{
					stari[counts]=i;
					starj[counts]=j;
					counts++;
					if(i<mini) mini=i;
					if(i>maxi) maxi=i;
					if(j<minj) minj=j;
					if(j>maxj) maxj=j;
				}			
			}		
		}
		if(counts==0) mintime=0;		
		else if(counts==1) mintime=1;
		else
		{
			for(int i=0;i<n;i++)
			{			
				for(int j=0;j<m;j++)
				{
					int mx1=0,mx2=0;
					mx1=max(fabs(i-mini),fabs(i-maxi));
					mx2=max(fabs(j-minj),fabs(j-maxj));
					int temptime=max(mx1,mx2);
					if(temptime<mintime) mintime=temptime;
					if(mintime==1) break;	
				}
				if(mintime==1) break;
			}		
			mintime+=1;
		}
		printf("%lld\n",mintime);
		t--;	
	}
	return 0;
}
