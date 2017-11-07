#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
long long int prime[10000]={0},pindex=0;
long long int p[100001]={0};
int naut[100002]={0};
int main()
{
	for(int i=2;i<100001;i++)
	{
		if(p[i]==0)
		{
			prime[pindex++]=i;
			for(int j=2;i*j<100001;j++)
			{
				p[i*j]=1;
			}
		}
	}
	naut[1]=1; naut[0]=0;
	for(int i=2;i<100001;i++)
	{
		int pfact=0,dig=0;
		int temp=i;
		while(temp>0) temp/=10,dig++;
		temp=i;
		if(p[i]==0) pfact=1;
		else
		{
			int ind=0;
			while(temp!=1)
			{
				if(temp%prime[ind]==0)
				{
					pfact++;
					while(temp%prime[ind]==0) temp/=prime[ind]; 
				}
				ind++;
			}
		}
		if(pfact==dig) naut[i]=naut[i-1]+1;
		else naut[i]=naut[i-1];
	}
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int a,b,count=0;
		scanf("%d%d",&a,&b);
		count=naut[b]-naut[a-1];
		printf("%d\n",count);

	}
	
	return 0;
}