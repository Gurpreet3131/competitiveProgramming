#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	long long int prime[664580]={0};
	int *p;
	p=new int[10000000];
	int index=1;
	for(int i=2;i<10000000;i++)
	{
		if(p[i]==0)
		{
			prime[index++]=i;
			for(int j=2;j*i<10000000;j++)
			{
				p[i*j]=1;
			}
		}
	}
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n; scanf("%d",&n);
		printf("%lld\n",prime[n]);
		t--;
	}
}