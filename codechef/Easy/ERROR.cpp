#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	char s[100001]; 
	while(t>0)
	{
				
		scanf("%s",s);
		bool found=false;
		int length=strlen(s);	
		for(int i=0;i<length-2;i++)
		{
			if( (s[i]=='0' && s[i+1]=='1' && s[i+2]=='0') || (s[i]=='1' && s[i+1]=='0' && s[i+2]=='1'))
			{
				found=true; break;
			}
		}
		if(found==true) printf("Good\n");
		else printf("Bad\n");
		t--;
	}
	return 0;
}
