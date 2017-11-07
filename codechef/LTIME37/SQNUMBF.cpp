#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	long long int a[101]={0},big=1000000000000;
	while(t>0)
	{
		int n,flag=0;
		scanf("%d",&n);
		long long int p=1;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(flag==0) 
			{
				p*=a[i];
				if(p>big || p<0) flag=1;
			}
			if(flag==0)
			{
				if(a[i]>big) flag=1;
			}
		}
		long long int number=0;
		if(flag==0)
		{
			long long int sq=sqrt(p);
			for(long long int i=2;i<=sq;i++)
			{
				if(p%(i*i)==0)
				{
					number=i;
					break;
				}
			}
		}
		else
		{
			p=1;
			for(int j=0;j<n;j++)
			{
				long long int sq=sqrt(a[j]);
				for(long long int i=2;i<=sq;i++)
				{
					if(a[j]%(i*i)==0)
					{
						number=i;
						break;
					}	
				}
				if(number!=0) break;
			}
		}
		printf("%lld\n",number);
		t--;
	}
    return 0;
}