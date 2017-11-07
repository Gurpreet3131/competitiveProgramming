#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main()
{
    int x,y,a[3]={0};
	scanf("%d%d",&x,&y);
	a[0]=y; a[1]=y; a[2]=y;
	if(y==x)
	{
		printf("0\n");
	}
	else
	{
		int ct=0;
		while(true)
		{	
			a[0]=min(a[1]+a[2]-1,x);
			sort(a,a+3);
			ct++;
			if(a[0]==x && a[1]==x && a[2]==x) break;
		}
		printf("%d\n",ct);
	}
	
	return 0;
}