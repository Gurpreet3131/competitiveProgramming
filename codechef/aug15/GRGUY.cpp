#include<bits/stdc++.h>
#include<string.h>
#define mod 1000000007
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	char s1[200001],s2[200001];
	while(t>0)
	{
		scanf("%s%s",s1,s2);
		int length=strlen(s1);
		int swap1=0,swap2=0,flag=0;
		int lane=1;
		for(int i=0;i<length;i++)
		{
			if(i==0)
			{
				if(s1[i]=='#') 
				{	
					flag++;
					swap1=mod;
					break;
				}
			}
			else if(lane==1)
			{
				if(s1[i]=='.') continue;
				else if(s1[i]=='#')
				{
					if(s2[i]=='#')
					{
						flag++;
						swap1=mod;
						break;
					}
					else 
					{
						lane=2;
						swap1++;
					}
				}
			}
			else
			{
				if(s2[i]=='.') continue;
				else if(s2[i]=='#')
				{
					if(s1[i]=='#')
					{
						flag++;
						swap1=mod;
						break;
					}
					else 
					{
						lane=1;
						swap1++;
					}
				}
			}
			
		}
		lane=2;
		for(int i=0;i<length;i++)
		{
			if(i==0)
			{
				if(s2[i]=='#') 
				{	
					flag++;
					swap2=mod;
					break;
				}
			}
			else if(lane==1)
			{
				if(s1[i]=='.') continue;
				else if(s1[i]=='#')
				{
					if(s2[i]=='#')
					{
						flag++;
						swap2=mod;
						break;
					}
					else 
					{
						lane=2;
						swap2++;
					}
				}
			}
			else
			{
				if(s2[i]=='.') continue;
				else if(s2[i]=='#')
				{
					if(s1[i]=='#')
					{
						flag++;
						swap2=mod;
						break;
					}
					else 
					{
						lane=1;
						swap2++;
					}
				}
			}
		}
		if(flag==2) printf("No\n");
		else if(flag<2)
		{
			printf("Yes\n%d\n",swap1<swap2?swap1:swap2);
		}
		t--;
	}
	return 0;
}