#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <cmath>
using namespace std;
int a,b,c;
int adj[27][27]={0},depth[27]={0};
void update(int a,int b)
{
	if(depth[a]==0) depth[a]=1;
	if(adj[a][b]==0)
	{
		adj[a][b]=1;
		depth[b]=max(depth[a]+1,depth[b]);
	}
	else
	{
		depth[b]=max(depth[a]+1,depth[b]);
	}
	int queue[10000],front=0,rear=0;
	queue[rear++]=b;
	while(front<rear)
	{
		int node=queue[front++];
		for(int i=0;i<26;i++)
		{
			if(adj[node][i]==1)
			{
				if(depth[i]==depth[node]) depth[i]++,queue[rear++]=i;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);	
	while(n-->0)
	{
		char aa,bb,cc;
		//scanf("%c %c %c",&aa,&bb,&cc);
		cin>>aa>>bb>>cc;
		a=aa-'a'; b=bb-'a'; c=cc-'a';
		update(a,b); 
		update(b,c);
		/*cout<<"next:\n";
		for(int i=0;i<26;i++)
		{
			if(depth[i]>0) cout<<(char)(i+'a')<<" "<<depth[i]<<endl;
		}*/
	}
	int d=1;
	while(true)
	{
		int flag=0;
		for(int i=0;i<26;i++)
		{
			if(depth[i]==d)
			{
				flag=1;
				printf("%c",i+'a'); break;
			}
		}
		d++;
		if(flag==0) break;
	}
	return 0;
}