#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n; scanf("%d",&n);
		int *coin;
		coin=new int[n];
		int sum=0,money=0,count=0;		
		for(int i=0;i<n;i++)
		{	
			scanf("%d",&coin[i]);
			sum+=coin[i];
		}		
		sort(coin,coin+n);
		if(sum==0)
		{
			printf("%d",count);
			t--; continue;
		}		
		for(int i=n-1;i>=0;i--)
		{
			if(money>sum)
			{
				break;
			}
			money+=coin[i];
			sum-=coin[i];
			count++;
		}
		
		printf("%d\n",count);
		
		t--;
	}
	return 0;
}
