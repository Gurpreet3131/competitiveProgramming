#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	char s[100004];
	while(t-->0)
	{
		int c0=0,c1=0;
		scanf("%s",s);
		int length=strlen(s);
		for(int i=0;i<length;i++)
		{
			if(s[i]=='0') c0++;
			else c1++;
		}
		if(c0==1 || c1==1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}