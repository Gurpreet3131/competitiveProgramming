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
		char p[10002][2];
		int count=0,index=0;		
		for(int i=0;i<strlen(s)-1;i++)
		{
			int flag=0;			
			if(index==0)
			{
				p[index][0]=s[i]; p[index][1]=s[i+1];
				count++;	index++;		
			}
			else
			{
				for(int j=0;j<index;j++)
				{
					if(p[j][0]==s[i] && p[j][1]==s[i+1])
					{
						flag=1; break;
					}
				}
				if(flag==0) 
				{
					p[index][0]=s[i]; p[index][1]=s[i+1];
					count++;	index++;		
				}
				flag=0;
			}
			//cout<<p[index-1][0]<<"   "<<p[index-1][1]<<endl;
		}			
		printf("%d\n",count);
		t--;
	}
	
	return 0;
}
