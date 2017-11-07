#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		char s[100];
		int l=0,tc=0,ic=0,m=0,e=0;
		cin>>s;
		int length=strlen(s);
		for(int i=0;i<length;i++)
		{
			if(s[i]=='L') l++;
			if(s[i]=='T') tc++;
			if(s[i]=='I') ic++;
			if(s[i]=='M') m++;
			if(s[i]=='E') e++;
		}
		
		if(length>10)
		{	
		if( (l>=2)&&(tc>=2)&&(ic>=2)&&(m>=2)&&e>=2) printf("YES\n");
		else printf("NO\n");
		}
		else
		{
			if( (l>=2)&&(tc>=2)&&(ic>=2)&&(m>=2)&&e>=1) printf("YES\n");
		else printf("NO\n");
		}		
		t--;
	}
	return 0;
}
