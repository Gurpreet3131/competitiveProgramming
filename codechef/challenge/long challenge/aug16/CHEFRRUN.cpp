#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;
long long int a[100002]={0};
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int n,count=0;
		scanf("%d",&n);
		int magic[n+1]={0};
		int visited[n+1]={0};
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
		{
			if(magic[i]==1 || magic[i]==-1) continue;
			long long int index=i;
			while(true)
			{
				visited[index]=i;
				index+=a[index]+1;
				if(index>n) index%=n;
				if(index==0) index=n;
				if(visited[index]==i && magic[index]==0)
				{
					long long int node = i;
					while(node != index)
					{
						if(magic[node]!=0) break;
						magic[node] = -1;
						node+=a[node]+1;
						if(node>n) node%=n;
						if(node == 0 ) node=n;
					}
					node = index;
					magic[node]=1;
					node+=a[node]+1;
					if(node>n) node%=n;
					if(node==0) node=n;
					while(node!=index)
					{
						if(magic[node]!=0) break;
						magic[node]=1;
						node+=a[node]+1;
						if(node>n) node%=n;
						if(node==0) node=n;
					}
					break;
				}
				else if(magic[index]==1 || magic[index]==-1)
				{
					long long int node = i;
					while(node != index)
					{
						if(magic[node]!=1) magic[node]=-1;
						else break;
						node+=a[node]+1;
						if(node>n) node%=n;
						if(node==0) node=n;
					}
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(magic[i]==1) count++;
		}
		printf("%d\n",count);
	}
	return 0;
}