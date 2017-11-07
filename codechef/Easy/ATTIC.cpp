#include<iostream>
#include<stdio.h>
#include<string.h>
#define mod 10000009
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		char s[1000001];
		scanf("%s",s); 
		int days=0,maxjump=1,start,dif;
		for(int i=0;i<strlen(s);i++)
		{
			if(s[i]=='.' && s[i-1]=='#')
			{
				start=i-1;
			}
			else if(s[i]=='#' && s[i-1]=='.')
			{
				dif=i-start;
				if(dif>maxjump) 
				{
					days++; maxjump=dif;
				}			
			}
		}	
		printf("%d\n",days);
		t--;
	}     
	return 0;
}
