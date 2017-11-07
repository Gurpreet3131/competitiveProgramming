#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	int a[1002];
	while(t-->0)
	{
		int n; scanf("%d",&n);
		int count[1007]={0};
		for(int i=0;i<n;i++) 
		{
			scanf("%d",&a[i]);
			count[a[i]]++;
		}
		int one=0,two=0;
		for(int i=1000;i>0;i--)
		{
			if(one==0)
			{
				if(count[i]>3)
				{
					one=i, two=i; break;
				}
				else if(count[i]>1) one=i;
			}
			else
			{
				if(count[i]>1)
				{
					two=i; break;
				}
			}
		}
		if(two==0) printf("-1\n");
		else printf("%d\n",one*two);
	}	
	return 0;
}