#include <iostream>
#include <stdio.h>
using namespace std;
int val[100001]={0},vv[100001]={0};
int path[100001],pindex=0;
int path2[100001],pindex2=0;
int adj[25001][10001]={0};
int index[25001]={0},queue[100001]={0};
void pathfind(int s,int d)
{
	if(s==d)
	{
		pindex=0;
		path[pindex++]=s;
		return;
	}
	int pred[25001]={0};
	pred[s]=-1; 
	int front=0,rear=0,flag=0;
	queue[rear++]=s; pindex=0;
	while(front<rear)
	{
		int node=queue[front++];
		for(int i=0;i<index[node];i++)
		{
			int nod=adj[node][i];
			if(pred[nod]==0)
			{
				queue[rear++]=adj[node][i];
				pred[nod]=node;
			}
			if(nod==d) 
			{
				flag=1; break;
			}
		}
		if(flag==1) break;
	}
	int temp=d;
	//cerr<<"in func\n";
	while(temp!=-1)
	{
		path[pindex++]=temp;
		temp=pred[temp];
		//cerr<<temp<<" "<<pred[temp]<<endl;
	}
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&val[i]);
	} 
	for(int i=1;i<n;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		adj[u][index[u]++]=v;
		adj[v][index[v]++]=u;
	}
	for(int query=1;query<=q;query++)
	{
		int type,ul,ur,vl,vr;
		scanf("%d%d%d",&type,&ul,&ur);
		pathfind(ul,ur);

		pindex2=0;
		for(int i=pindex-1;i>=0;i--)
		{
			path2[pindex2++]=path[i];
		}
		pindex2--;
		
		//cout<<"path2=\n";
		//for(int i=0;i<=pindex2;i++) cerr<<path2[i]<<" ";
		//	cerr<<endl;

		if(type==1)
		{
			for(int i=0;i<=pindex2;i++)
			{
				vv[i]=val[path2[i]];
			}
			for(int i=0;i<=pindex2;i++)
			{
				val[path2[i]]=vv[pindex2-i];
			}
		}
		else
		{
			scanf("%d%d",&vl,&vr);
			pathfind(vl,vr);
			pindex--;

			//cout<<"path=\n";
			//for(int i=0;i<=pindex;i++) cerr<<path[i]<<" ";
			//cerr<<endl;

			for(int i=0;i<=pindex;i++) 
			{
				vv[i]=path[i];
			}
			for(int i=0;i<=pindex;i++)
			{
				path[i]=vv[pindex-i];
			}

			if(type==2)
			{
				int flag=1;
				for(int i=0;i<=pindex2;i++)
				{
					if(val[path2[i]]!=val[path[i]])
					{
						flag=0; break;
					}
				}
				if(flag==1) printf("Yes\n");
				else printf("No\n");
			}
			else
			{
				for(int i=0;i<=pindex2;i++)
				{
					vv[i]=path2[i];
				}
				for(int i=0;i<=pindex2;i++)
				{
					val[path[i]]=val[path2[i]];
				}
			}
		}
	}
	return 0;
}