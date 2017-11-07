#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	char s[12347];
	while(t-->0)
	{
		scanf("%s",s);
		int length=strlen(s);
		int j=length-1,flag=1;
		for(int i=0;i<=j;i++)
		{
			if(s[i]=='.')
			{
				if(s[j]=='.') s[i]='a',s[j]='a';
				else s[i]=s[j]; 
			}
			else if(s[j]=='.') s[j]=s[i];
			else if(s[i]!=s[j])
			{
				flag=0; break;
			}
			j--;
		}
		if(flag==0) printf("-1\n");
		else printf("%s\n",s);
	}
	return 0;
}