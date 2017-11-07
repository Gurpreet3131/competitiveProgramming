#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cstring>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		char s[10002];		
		scanf("%s",s);
		int count=1;		
		for(int i=1;i<strlen(s)-1;i++)
		{
			int flag=0;			
			for(int j=0;j<i;j++)
			{
				//cout<<s[j]<<s[j+1]<<s[i]<<s[i+1];
				if(s[j]==s[i] && s[j+1]==s[i+1])
				{
					
					flag=1; 
				}
				if(flag==1) break;
			}
			if(flag==0) 
			{
				count++;		
			}
			
			
		}			
		printf("%d\n",count);
		t--;
	}
	
	return 0;
}
