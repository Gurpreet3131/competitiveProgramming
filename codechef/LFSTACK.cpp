#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#define mod 1000000007
using namespace std;
int seq[1000003]={0};
int n,**st;
int rec(int index[],int cur[],int sindex,int call)
{
	int flag;
	if(call!=-1)
	{
		cur[call]++;
	}
	if(sindex==0)
	{
		flag=1;
		for(int i=0;i<n;i++)
		{
			if(cur[i]<index[i])
			{
				if(st[i][cur[i]]!=seq[sindex])
				{
					flag=0; break;
				}
			} 
		}
		return flag;
	}
	else
	{
		flag=0;
		for(int i=0;i<n;i++)
		{
			if(cur[i]<index[i])
			{
				if(st[i][cur[i]]==seq[sindex])
				{
					int val=rec(index,cur,sindex-1,i);
					if(val==1) 
					{
						flag=1;
					}
				}
			}
		}
	}
	if(flag==0 && call!=-1) cur[call]--; 
	return flag;
}
int main()
{
	int t;
	scanf("%d",&t);
	
	while(t-->0)
	{
		int sum=0;
		scanf("%d",&n);
		int *index,*cur;
		cur=new int[n+1];
		index=new int[n+1];
		st= new int*[n+1];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&index[i]);
			sum+=index[i];
			st[i]=new int[index[i]+1];
			for(int j=0;j<index[i];j++)
			{
				scanf("%d",&st[i][j]);
			}
		}
		for(int i=0;i<sum;i++)
		{
			scanf("%d",&seq[i]);
		}
		int sindex=sum-1,flag=1;
		if(n==1)
		{
			for(int i=0;i<index[0];i++)
			{
				if(st[0][i]!=seq[sindex--])
				{
					flag=0;
					break;
				}
			}
		}
		else
		{
			flag=rec(index,cur,sindex,-1);
		}
		if(flag==1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}