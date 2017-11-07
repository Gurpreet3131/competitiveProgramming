#include <bits/stdc++.h>
using namespace std;
long long int a[503][503]={0};
long long rsum[504]={0},csum[503]={0};
int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&a[i][j]);
			rsum[i]+=a[i][j];
			csum[j]+=a[i][j];
		}
	}
	long long int mid,s=0,e=500000000000,ct=0;
	while(ct!=p-1)
	{
		ct=0;
		mid=(s+e)/2; 
		long long int sum=0;
		for(int i=0;i<n;i++)
		{		
			sum+=rsum[i];
			if(sum>mid)
			{
				sum=0; 
				if(i!=0 && i!=n)ct++;
				if(rsum[i]<=mid) i--;
			}
		}
		if(ct>p-1)
		{
			s=mid;
			mid=(s+e)/2;
		}	
		else if(ct<p-1)
		{
			e=mid;
			mid=(s+e)/2;
		}
		cout<<mid<<" ";
	}
	int set1[503],rear1=0;
	long long int sum=0;
	for(int i=0;i<n;i++)
	{		
		sum+=rsum[i];
		if(sum>mid)
		{
			sum=0; 
			if(i!=0 && i!=n) 
			{
				set1[rear1++]=i;
			}
			if(rsum[i]<=mid) i--;
		}
	}
	s=0,e=500000000000,ct=0;
	while(ct!=p-1)
	{
		ct=0;
		mid=(s+e)/2; 
		long long int sum=0;
		for(int i=0;i<n;i++)
		{		
			sum+=csum[i];
			if(sum>mid)
			{
				sum=0; 
				if(i!=0 && i!=n)ct++;
				if(csum[i]<=mid) i--;
			}
		}
		if(ct>p-1)
		{
			s=mid;
			mid=(s+e)/2;
		}	
		else if(ct<p-1)
		{
			e=mid;
			mid=(s+e)/2;
		}
	}
	int set2[503],rear2=0;
	for(int i=0;i<n;i++)
	{		
		sum+=csum[i];
		if(sum>mid)
		{
			sum=0; 
			if(i!=0 && i!=n) 
			{
				set2[rear2++]=i;
			}
			if(csum[i]<=mid) i--;
		}
	}
	for(int i=0;i<rear1;i++) printf("%d ",set1[i]);
		printf("\n");
	for(int i=0;i<rear2;i++) printf("%d ",set2[i]);
		printf("\n");
	
	return 0;
}