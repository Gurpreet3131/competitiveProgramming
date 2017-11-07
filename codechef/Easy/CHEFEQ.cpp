#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		int n,count[100001]={0},a;	
		scanf("%d",&n);
		for(int i=0;i<n;i++) 
		{
			scanf("%d",&a);
			count[a]++;	
		}
		int c=0;		
		for(int i=1;i<=n;i++)
		{
			if(count[i]>c) c=count[i];
		}
		c=n-c;
		printf("%d\n",c);
		t--;
	}
	
	return 0;
}
