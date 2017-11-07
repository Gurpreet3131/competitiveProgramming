#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
long long int segtree[400002]={0},lazy[400002]={0};
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

	segtree[nodenum]= segtree[nodenum*2]+segtree[nodenum*2+1];
	lazy[nodenum]=0;
}
void lazyUpdate(int s,int e,int nodenum)
{
	segtree[nodenum] += lazy[nodenum];
	if(e>s) //it is not a leaf node
	{
		lazy[nodenum]/=(e-s+1);
		int mid=(s+e)/2;
		lazy[nodenum*2]+=lazy[nodenum]*(mid-s+1);
		lazy[nodenum*2+1]+=lazy[nodenum]*(e-(mid+1)+1);
	}
	lazy[nodenum]=0;
}

void setLazy(int s,int e,long long int newval,int nodenum)
{
	if(e>s)
	{
		int mid=(s+e)/2;
		lazy[nodenum*2]+=(mid-s+1)*newval;
		lazy[nodenum*2+1]+=(e-(mid+1)+1)*newval;
	}
}

void rangeUpdate(int l,int r,long long int newval,int s,int e,int nodenum)
{
	if(lazy[nodenum]>0)
		lazyUpdate(s,e,nodenum);
	if(s>r || e<l) return;
	else if(s>=l && e<=r)
	{
		//cout<<nodenum<<endl;
		//cout<<newval<<endl;
		segtree[nodenum]+= (e-s+1)*newval;
		setLazy(s,e,newval,nodenum);
	} 
	else
	{
		int mid=(s+e)/2;
		//cout<<nodenum*2<< " "<<nodenum*2+1<<endl;
		rangeUpdate(l,r,newval,s,mid,nodenum*2);
		rangeUpdate(l,r,newval,mid+1,e,nodenum*2+1);

		segtree[nodenum]=segtree[nodenum*2]+segtree[nodenum*2+1];
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
		int n,m;
		scanf("%d%d",&n,&m);
 		buildsegtree(1,n,1);
		for(int i=1;i<=m;i++)
		{
			long long int type,p,q,v;
			scanf("%lld%lld%lld",&type,&p,&q);
			if(type==0)
			{
				scanf("%lld",&v);
				rangeUpdate(p,q,v,1,n,1);
			}
			else
			{
				long long int ans=query(p,q,1,n,1);
				printf("%lld\n",ans);
			}
			//for(int i=1;i<=2*n;i++) cout<<segtree[i]<<" ";
			//	cout<<endl;
			//for(int i=1;i<=2*n;i++) cout<<lazy[i]<<" ";
 			//cout<<endl;
 		}	
	}
	return 0;
}