#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <time.h>
using namespace std;
long long int a[501][501],rowsum[503]={0},colsum[503][503]={0};
long long int rsum[503][503]={0},csum[503]={0};
int mark[503]={0},mark2[503]={0},n;
int set1[503]={0},set2[503]={0},set3[503]={0},set4[503]={0};
int main()
{
	int p;
	scanf("%d%d",&n,&p);
	mark[0]=1; mark[n]=1;
	mark2[0]=1; mark2[n]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&a[i][j]);	
			rowsum[i]+=a[i][j];		
		}
	}
	int queue[503]={0},ind=0,q2[503]={0},ind2=0;

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
	int setindex=1;
	for(int i=1;i<n;i++)
	{
		if(mark[i]==1) set1[setindex++]=i;
	} 

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
		ind2=0;
		for(int j=0;j<=n;j++)
		{
			if(mark2[j]==1) q2[ind2++]=j;
		}	
		int s,e;
		long long int maxsum=0;

		for(int j=0;j<ind2-1;j++)
		{
			int start=q2[j],end=q2[j+1];
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
		mark2[val]=1;
	}
	setindex=1; ind2=0;
	for(int i=0;i<=n;i++)
	{
		if(mark2[i]==1) q2[ind2++]=i;
	}
	for(int i=1;i<n;i++)
	{
		if(mark2[i]==1) set2[setindex++]=i;
	}
	long long int maxans=0,maxans2=0;
	for(int i=0;i<ind-1;i++)
	{
		int sr=queue[i],er=queue[i+1];
		for(int j=0;j<ind2-1;j++)
		{
			int sc=q2[j],ec=q2[j+1];
			long long int sum=0;
			for(int k=sc;k<ec;k++)
			{
				sum+=colsum[i][k];
			}
			if(sum>maxans) maxans=sum;
		}
	}
	

	/////
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			csum[j]+=a[i][j];
		}
	}
	ind=0;ind2=0;
	for(int i=1;i<n;i++) mark[i]=0,mark2[i]=0;

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
				sum+=csum[j];
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
	setindex=1;
	for(int i=1;i<n;i++)
	{
		if(mark[i]==1) set3[setindex++]=i;
	} 

	for(int i=0;i<ind-1;i++)
	{
		int start=queue[i],end=queue[i+1];
		for(int j=0;j<n;j++)
		{
			for(int k=start;k<end;k++)
			{
				rsum[i][j]+=a[j][k];
			}
		}
	}

	for(int i=1;i<=p-1;i++)
	{
		ind2=0;
		for(int j=0;j<=n;j++)
		{
			if(mark2[j]==1) q2[ind2++]=j;
		}	
		int s,e;
		long long int maxsum=0;

		for(int j=0;j<ind2-1;j++)
		{
			int start=q2[j],end=q2[j+1];
			if(end-start==1) continue;
			long long int maxpartsum=0;
			for(int k=0;k<p;k++)
			{
				long long int sum=0;
				for(int l=start;l<end;l++)
				{
					sum+=rsum[k][l];
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
		mark2[val]=1;
	}
	setindex=1; ind2=0;
	for(int i=0;i<=n;i++)
	{
		if(mark2[i]==1) q2[ind2++]=i;
	}
	for(int i=1;i<n;i++)
	{
		if(mark2[i]==1) set4[setindex++]=i;
	}

	for(int i=0;i<ind-1;i++)
	{
		int sr=queue[i],er=queue[i+1];
		for(int j=0;j<ind2-1;j++)
		{
			int sc=q2[j],ec=q2[j+1];
			long long int sum=0;
			for(int k=sc;k<ec;k++)
			{
				sum+=rsum[i][k];
			}
			if(sum>maxans2) maxans2=sum;
		}
	}

	///
	//cout<<maxans<<" "<<maxans2<<endl;
	if(maxans<maxans2)
	{
		for(int i=1;i<=p-1;i++)
		{
			printf("%d ",set1[i]);
		}
		cout<<endl;

		for(int i=1;i<=p-1;i++)
		{
			printf("%d ",set2[i]);
		}
		cout<<endl;	
	}
	else
	{
		for(int i=1;i<=p-1;i++)
		{
			printf("%d ",set4[i]);
		}
		cout<<endl;

		for(int i=1;i<=p-1;i++)
		{
			printf("%d ",set3[i]);
		}
		cout<<endl;
	}
	

	return 0;
}