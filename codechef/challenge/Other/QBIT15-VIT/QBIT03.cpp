#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int b,m,n,*range;
		scanf("%d%d%d",&b,&m,&n);
		range=new int[n];
		int sum=0,flag=1;		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&range[i]);
			sum+=range[i];
		}
		sort(range,range+n);
		for(int i=0;i<n;i++)
		{
			if( (b+sum)>m && b-range[i]<0)
			{
				flag=0;	
				break;
			}
			else if(b+sum>m)
			{
				b-=range[i];
				sum-=range[i];
			}
			if(b+sum<=m)
			{
				flag=1;
				b+=sum;				
			}
		}
		if(flag==1)  printf("%d\n",b);
		else printf("%d\n",-1);

		t--;
	}
	return 0;
}
