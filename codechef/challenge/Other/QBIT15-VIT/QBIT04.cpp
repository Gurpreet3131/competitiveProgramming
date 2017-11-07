#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		unsigned int n; scanf("%u",&n);
		int ai;
		unsigned int sum=0;
		for(int i=0;i<n;i++)	
		{
			scanf("%d",&ai);
			sum+=ai;
		}
		
		if(sum%n==0 && sum!=0) printf("%u\n",sum/n);
		else printf("%d\n",-1);
		t--;
	}
	return 0;
}
