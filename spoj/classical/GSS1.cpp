#include <iostream>
#include <stdio.h>
using namespace std;
long long int segtree[200000];
long long int a[50001]={0};
void buildsegtree(int s,int e,int nodenum)
{
	if(s==e)
	{
		segtree[nodenum]=a[s];
		return;
	}
	int mid=(s+e)/2;
	buildsegtree(s,mid,nodenum*2);
	buildsegtree(mid+1,e,nodenum*2+1);

	segtree[nodenum]= segtree[nodenum*2]+segtree[nodenum*2+1];
}

long long int query(int l,int r,int s,int e,int nodenum)
{
	if(s>r || e<l) return 0;
	else if(s>=l && e<=r) return segtree[nodenum];
	else
	{
		int mid=(s+e)/2;
		return query(l,r,s,mid,nodenum*2)+query(l,r,mid+1,e,nodenum*2+1);
	}
}

void pointupdate(int p,int newvalue,int s,int e,int nodenum)
{
	if(s==e) 
	{
		segtree[nodenum]=newvalue;
		return;
	}

	int mid=(s+e)/2;
	if(p<=mid) pointupdate(p,newvalue,s,mid,nodenum*2);
	else pointupdate(p,newvalue,mid+1,e,nodenum*2+1);

	segtree[nodenum]=segtree[nodenum*2]+segtree[nodenum*2+1];
}

int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	} 
	buildsegtree(1,n,1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		long long int max=0;
		for(int i=l;i<=r;i++)
		{
			for(int j=i;j<=r;j++)
			{
				long long int ans=query(i,j,1,n,1);
				if(ans>max) max=ans;
			}
		}
		printf("%lld\n",max);
	}
	return 0;
}