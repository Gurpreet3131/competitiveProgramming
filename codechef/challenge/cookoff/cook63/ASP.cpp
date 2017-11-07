#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n,*num,*sorted; scanf("%d",&n);
		num=new int[n];
		sorted=new int[n];
		bool r=true;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			sorted[i]=num[i];
		}		
		sort(sorted,sorted+n);
		if(n==1) 
		{
			printf("YES\n");
			t--;continue;
		}
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				if(sorted[i]!=num[i] && sorted[i]!=num[i+1] )
				{
					r=false; break;
				}
			}			
			else if(i==n-1)
			{
				if(sorted[i]!=num[i] && sorted[i]!=num[i-1] )
				{
					r=false; break;
				}
			}
			else 
			{
				if(sorted[i]!=num[i] && sorted[i]!=num[i-1] && sorted[i]!=num[i+1] )
				{
					r=false; break;
				}
			}
		}
		if(r==true) printf("YES\n"); 
		else printf("NO\n");
		t--;
	}
	return 0;
}
