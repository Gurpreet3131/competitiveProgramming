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
	int t,a[52]; 
	scanf("%d",&t);
	char turn[4];
	while(t-->0)
	{
		int n; scanf("%d",&n);
		cin>>turn;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		if(turn[1]=='e')
		{
			if(n==1 && a[0]%2==0)
			{
				printf("Dee\n");
			}
			else printf("Dum\n");
		}
		else printf("Dum\n");
	}
	return 0;
}