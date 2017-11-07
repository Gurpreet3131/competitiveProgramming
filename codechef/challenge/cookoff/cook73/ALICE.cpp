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
	while(t-->0)
	{
		int n; scanf("%d",&n);
		int x1,x2,y1,y2,tempx1,tempx2;
		x1=0;y1=0; x2=n; y2=1;
		for(int i=0;i<n;i++)
		{
			printf("%d %d %d %d\n",x1,y1,x2,y2);
			if(i%2==0)
			{
				y1+=2;
			}
			else
			{
				y2+=2;
			}
		}
		printf("%d %d %d %d\n",0,1,n,0);
	}
	return 0;
}