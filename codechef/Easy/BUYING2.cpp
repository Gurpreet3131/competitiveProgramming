#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n,k; scanf("%d%d",&n,&k);
		int min,sum=0,note;		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&note);
			sum+=note;
			if(i==0) min=note;
			if(min>note) min=note;
		}
		if((sum%k)<min)
		{
			printf("%d\n",sum/k);	
		}
		else printf("%d\n",-1);
		t--;
	}
	return 0;
}
