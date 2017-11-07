#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
using namespace std;
int prime[100000]={0},pindex=0;
int p[1000005]={0};
int main()
{
	for(int i=2;i<=1000005;i++)
	{
		if(p[i]==0)
		{
			prime[pindex++]=i;
			for(int j=2;i*j<=1000005;j++)
			{
				p[i*j]=1;
			}
		}
	}
	int t; scanf("%d",&t);
	while(t-->0)
	{
		int n; scanf("%d",&n);
		int temp=n,index=0;
		while(temp!=1)
		{
			if(p[temp]==0)
			{
				printf("%d ",temp);
				temp=1;
				break;
			}
			if(temp%prime[index]==0)
			{
				while(temp%prime[index]==0)
				{
					printf("%d ",prime[index]);
					temp/=prime[index];
				}
			}
			index++;
		}
		printf("\n");
	}	
	return 0;
}