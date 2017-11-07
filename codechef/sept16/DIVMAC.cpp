#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;
int p[1000001]={0},segtree[400001]={0};
int a[100002]={0},maxtree[400001]={0};
void buildsegtree(int s,int e,int nodenum)
{
	if(s==e)
	{
		segtree[nodenum]=a[s];
		maxtree[nodenum]=p[a[s]];
		return;
	}
	int mid=(s+e)/2;
	buildsegtree(s,mid,nodenum*2);
	buildsegtree(mid+1,e,nodenum*2+1);
	maxtree[nodenum]=max(maxtree[nodenum*2],maxtree[nodenum*2+1]);
	segtree[nodenum]= 0;
}
void rangeUpdate(int l,int r,long long int newval,int s,int e,int nodenum)
{
	if(s>r || e<l) return;
	else if(maxtree[nodenum]==1) return;
	else if(s>=l && e<=r && s==e)
	{
		//cout<<"\nEnter:"<<p[segtree[nodenum]]<<endl;
		segtree[nodenum] /= p[segtree[nodenum]];
		maxtree[nodenum]= p[segtree[nodenum]];
	} 
	else
	{
		int mid=(s+e)/2;
		//cout<<nodenum*2<< " "<<nodenum*2+1<<endl;
		//cout<<s<<": "<<mid<<endl;
		rangeUpdate(l,r,newval,s,mid,nodenum*2);
		//cout<<mid+1<<": "<<e<<endl;
		rangeUpdate(l,r,newval,mid+1,e,nodenum*2+1);
		maxtree[nodenum]=max(maxtree[nodenum*2],maxtree[nodenum*2+1]);
		segtree[nodenum]= 0;
	}
}

long long int query(int l,int r,int s,int e,int nodenum)
{
	if(s>r || e<l) return 0;
	else if(s>=l && e<=r) return maxtree[nodenum];
	else
	{
		int mid=(s+e)/2;
		return max(query(l,r,s,mid,nodenum*2),query(l,r,mid+1,e,nodenum*2+1));
	}

}
int main()
{
	p[1]=1;
	for(int i=2;i<1000001;i++)
	{
		if(p[i]==0)
		{
			p[i]=i;
			for(int j=2;i*j<1000001;j++)
			{
				if(p[i*j]==0) p[i*j]=i;
			}
		}
	}
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int n,m,maxval;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		buildsegtree(1,n,1);
		for(int i=1;i<=m;i++)
		{
			int type,l,r;
			scanf("%d%d%d",&type,&l,&r);
			if(type==0)
			{
				rangeUpdate(l,r,1,1,n,1);	
			}
			else
			{
				maxval=query(l,r,1,n,1);
				printf("%d ",maxval);
			}
		}
	}	
	return 0;
}