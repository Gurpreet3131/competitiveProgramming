#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;
int nn=10000000;
long long int segtree[40000002]={0},lazy[40000002]={0};
void buildsegtree(int s,int e,int nodenum)
{
	if(s==e)
	{
		segtree[nodenum]=0;
		lazy[nodenum]=0;
		return;
	}
	int mid=(s+e)/2;
	buildsegtree(s,mid,nodenum*2);
	buildsegtree(mid+1,e,nodenum*2+1);

	segtree[nodenum]= 0;
	lazy[nodenum]=0;
}
void lazyUpdate(int s,int e,int nodenum)
{
	segtree[nodenum] = lazy[nodenum];
	if(e>s) //it is not a leaf node
	{
		int mid=(s+e)/2;
		lazy[nodenum*2] = lazy[nodenum];
		lazy[nodenum*2+1] = lazy[nodenum];
	}
	lazy[nodenum]=0;
}

void setLazy(int s,int e,long long int newval,int nodenum)
{
	if(e>s)
	{
		int mid=(s+e)/2;
		lazy[nodenum*2] = newval;
		lazy[nodenum*2+1] = newval;
	}
}

void rangeUpdate(int l,int r,long long int newval,int s,int e,int nodenum)
{
	if(lazy[nodenum]>0)
		lazyUpdate(s,e,nodenum);
	if(s>r || e<l) return;
	else if(s>=l && e<=r)
	{
		segtree[nodenum] = newval;
		setLazy(s,e,newval,nodenum);
	} 
	else
	{
		int mid=(s+e)/2;
		//cout<<nodenum*2<< " "<<nodenum*2+1<<endl;
		rangeUpdate(l,r,newval,s,mid,nodenum*2);
		rangeUpdate(l,r,newval,mid+1,e,nodenum*2+1);

		if(segtree[nodenum*2]==segtree[nodenum*2+1])
			segtree[nodenum]= segtree[nodenum*2];
	}
}

long long int query(int l,int r,int s,int e,int nodenum)
{
	if(lazy[nodenum]>0)
		lazyUpdate(s,e,nodenum);
	if(s>r || e<l) return 0;
	else if(s>=l && e<=r) return segtree[nodenum];
	else
	{
		int mid=(s+e)/2;
		return query(l,r,s,mid,nodenum*2)+query(l,r,mid+1,e,nodenum*2+1);
	}

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int n;
		scanf("%d",&n);
		buildsegtree(1,n,1);
		//memset(segtree,0,sizeof(segtree));
		//memset(lazy,0,sizeof(lazy));
		for(int i=1;i<=n;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			rangeUpdate(l,r,i,1,nn,1);
			//for(int i=1;i<2*n;i++) cout<<segtree[i]<<" ";
			//	cout<<endl;
			//for(int i=1;i<2*n;i++) cout<<lazy[i]<<" ";
			//	cout<<endl;
 		}
 		map<int,int>mp;
 		map<int,int> :: iterator itr;
 		int count=0;
 		for(int i=1;i<=n;i++)
 		{
 			int val=query(i,i,1,nn,1);
 			if(mp[val]==0)
 			{
 				count++; mp[val]++;
 			}
 		}	
 		printf("%d\n",count);
	}
	return 0;
}