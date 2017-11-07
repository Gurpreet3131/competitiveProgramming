#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	
	int n,l[5000],r[5000];
	scanf("%d",&n);
	int count=0,rr=0;	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(r[j]>r[j+1])
			{
				int templ=l[j];
				int tempr=r[j];
				l[j]=l[j+1]; l[j+1]=templ;
				r[j]=r[j+1]; r[j+1]=tempr;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(l[i]>rr)
		{
			count++; rr=r[i];
		}
	}
	printf("%d\n",count);
	return 0;
}
