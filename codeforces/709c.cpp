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
	char s[100003];
	scanf("%s",s);
	int length=strlen(s),start=0,count=0;
	for(int i=0;i<length;i++) if(s[i]=='a') count++;
	if(count==length)
	{
		s[length-1]='z';
	}
	else
	{
		for(int i=0;i<length;i++)
		{
			if(start==0)
			{
				if(s[i]!='a') s[i]--,start=1;
			}
			else
			{	
				if(s[i]!='a') s[i]--,start=1;
				else break;
			}
		}	
	}
	printf("%s\n",s);
	return 0;
}
