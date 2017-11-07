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
	int t; scanf("%d",&t);
	while(t-->0)
	{
		int n,m; scanf("%d%d",&m,&n);
		int count=0;
		for(int i=m;i<=n;i++)
		{
			int temp=i;
			int sum=0,p=1;
			while(temp>0)
			{
				int dig=temp%10;
				sum+=dig; p*=dig;
				temp/=10;
			}
			if(sum%2==0 && p%2==0)
			{
				int flag=1;
				if(i==2 || i==3 || i==5) flag=1;
				else if(i%2==0) flag=0;
				else
				{
					for(int j=3;j<=sqrt(i);j+=2)
					{
						if(i%j==0)
						{
							flag=0; break;
						}
					}
				}
				if(flag==1) count++;

			}  
		}
		printf("%d\n",count);
	}	
	return 0;
}