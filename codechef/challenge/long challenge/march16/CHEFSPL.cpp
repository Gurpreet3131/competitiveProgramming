#include<bits/stdc++.h>
#define mod 1000000007
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		char s[1000001];
		scanf("%s",s);
		int doubles=1,length=strlen(s);
		if(length==1) doubles=0;
		else if(length%2==0)
		{
			int half=length/2;
			for(int i=0;i<length/2;i++)
			{
				if(s[i]!=s[half++])
				{
					doubles=0; break;
				}
			}
		}
		else
		{
			int start=length/2,del=0;
			for(int i=0;i<length/2;i++)
			{
				if(s[i]==s[start])
				{
					start++; 
				}
				else 
				{
					if(del==0)
					{
						start++; i--; del=1;
					}
					else 
					{
						doubles=0; break;
					}
				}
			}
			if(doubles==0)
			{
				doubles=1; del=0; start=(length+1)/2;
				for(int i=0;i<(length+1)/2;i++)
				{
					if(doubles==1 && del==0 && i==length/2)
					{
						break;
					}
					else if(s[i]==s[start])
					{
						start++; continue;
					}
					else
					{
						if(del==0)
						{
							del=1;
						}
						else 
						{
							doubles=0; break;
						}
					}
				}
			}
		}
		if(doubles==1) printf("YES\n");
		else printf("NO\n");
		t--;
	}	
	return 0;    
}
