#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int pred[2001]={0},parent[2001]={0};
int main()
{
	int n,m;
	char s[104];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<m;j++)
		{
			if(s[j]=='.')
			{
				if((i+j)%2==0) printf("B");
				else printf("W");
			}
			else printf("-");
		}
		printf("\n");
	}
	return 0;
}