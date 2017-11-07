#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <cmath>
using namespace std;
int main()
{
	int t; 
	scanf("%d",&t);
	int p[1001]={0}; p[1]=1; p[0]=1;
	for(int i=2;i<1001;i++)
	{
		if(p[i]==0)
		{
			for(int j=2;i*j<1001;j++)		
			{
				p[i*j]=1;
			}	
		}
	}
	while(t-->0)
	{
		int n,ans=-1; 
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int num;
			scanf("%d",&num);
			if(p[num]==0)
			{
				if(num*num>ans) ans=num*num;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}