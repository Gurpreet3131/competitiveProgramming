#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <time.h>
using namespace std;
long long int a[501][501],rowsum[503]={0},colsum[503][503]={0};
int mark[503]={0},n;
int main()
{
	int p;
	scanf("%d%d",&n,&p);
	mark[0]=1; mark[n]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&a[i][j]);	
			rowsum[i]+=a[i][j];		
		}
	}
	int queue[503]={0},ind=0;

	for(int i=1;i<=p-1;i++)
	{
		ind=0;
		for(int j=0;j<=n;j++)
		{
			if(mark[j]==1) queue[ind++]=j;
		}	
		int s,e;
		long long int maxsum=0;
		for(int j=0;j<ind-1;j++)
		{
			int start=queue[j],end=queue[j+1];
			long long int sum=0;
			if(end-start==1) continue;
			for(int j=start;j<end;j++)
			{
				sum+=rowsum[j];
			}
			if(sum>maxsum)
			{
				maxsum=sum; s=start; e=end;
			}
		}
		int val=(s+e)/2;
		mark[val]=1;
	}
	ind=0;
	for(int i=0;i<=n;i++)
	{
		if(mark[i]==1) queue[ind++]=i;
	}
	for(int i=1;i<n;i++)
	{
		if(mark[i]==1) printf("%d ",i);
		mark[i]=0;
	} printf("\n");

	for(int i=0;i<ind-1;i++)
	{
		int start=queue[i],end=queue[i+1];
		for(int j=0;j<n;j++)
		{
			for(int k=start;k<end;k++)
			{
				colsum[i][j]+=a[k][j];
			}
		}
	}

	for(int i=1;i<=p-1;i++)
	{
		ind=0;
		for(int j=0;j<=n;j++)
		{
			if(mark[j]==1) queue[ind++]=j;
		}	
		int s,e;
		long long int maxsum=0;

		for(int j=0;j<ind-1;j++)
		{
			int start=queue[j],end=queue[j+1];
			if(end-start==1) continue;
			long long int maxpartsum=0;
			for(int k=0;k<p;k++)
			{
				long long int sum=0;
				for(int l=start;l<end;l++)
				{
					sum+=colsum[k][l];
				}
				if(sum>maxpartsum) maxpartsum=sum;
			}
			if(maxpartsum>maxsum)
			{
				maxsum=maxpartsum;
				s=start; e=end;
			}			
		}
		int val=(s+e)/2;
		mark[val]=1;
	}
	for(int i=1;i<n;i++)
	{
		if(mark[i]==1) printf("%d ",i);
		mark[i]=0;
	}
	printf("\n");
	return 0;
}