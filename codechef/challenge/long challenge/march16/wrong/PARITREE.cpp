#include<bits/stdc++.h>
#define mod 1000000007
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
int main()
{
	long long int twop[100001]={0};
	twop[0]=1; 
	for(int i=1;i<100001;i++)
	{
		twop[i]=twop[i-1]*2;
		if(twop[i]>=mod) twop[i]%=mod;
		//printf("%lld\n",twop[i]);
	}
	int t; scanf("%d",&t);
	int pre[100001]={0},qu[100001],qv[100001],qcount[100001]={0};
	while(t>0)
	{
		long long int n,q,ways=1;
		scanf("%lld%lld",&n,&q);
		int u,v;
		int *visited,count=n-1;
		//visited=new int[n+1];
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d",&u,&v);
			pre[v]=u;
		}
	//	cout<<"pre="<<endl;
	//	for(int i=1;i<=n;i++) cout<<i<< " "<<pre[i]<<endl;
		for(int i=0;i<q;i++)
		{
			int x;
			scanf("%d%d%d",&qu[i],&qv[i],&x);
			qcount[i]=0;
			int temp=qv[i];
			while(temp!=qu[i])
			{
				qcount[i]++;
//				cout<<"u v "<<pre[temp]<<" "<<temp<<endl;
				temp=pre[temp];
			}
		}	
//		cout<<"qcount="<<endl;
//		for(int i=0;i<q;i++) cout<<i<< " "<<qcount[i]<<endl;
		//sorting
		for(int i=0;i<q-1;i++)
		{
			int chng=0;
			for(int j=0;j<q-1-i;j++)
			{
				if(qcount[j]>qcount[j+1])
				{
					int temp;
					temp=qu[j]; qu[j]=qu[j+1]; qu[j+1]=temp;
					temp=qv[j]; qv[j]=qv[j+1]; qv[j+1]=temp;
					//temp=qx[j]; qu[j]=qx[j+1]; qx[j+1]=temp;
					temp=qcount[j]; qcount[j]=qcount[j+1]; qcount[j+1]=temp;
					chng++;
				}
			}
			if(chng==0) break;
		}
//		cout<<"qcount="<<endl;
//		for(int i=0;i<q;i++) cout<<i<< " "<<qcount[i]<<endl;
		int totalres=0;
		for(int i=0;i<q;i++)
		{
			int countres=0,total=qcount[i],tempnode=qv[i];
			//cout<<"visited "<<visited[i+1]<<endl;
			while(total>0)
			{
				 if(qcount[i]==1)
				 {
				 		totalres++; 
				 }
				 countres++; 
				int temp=tempnode;
				tempnode=pre[tempnode];
				pre[temp]=qu[i];
				total--;
			}
		//	cout<<"visited=\n";
		//	for(int l=1;l<=n;l++) cout<<l<<" "<<visited[l]<<endl;
		//	cout<<"qcount-countres=="<<qcount[i]-countres<<endl;
			ways*=twop[qcount[i]-countres-1];
			if(ways>=mod) ways%=mod;
		}
		//cout<<"totalres="<<totalres<<endl;

		ways*=twop[n-1-totalres];
		if(ways>=mod) ways%=mod;
		//if(q==0) ways=twop[n-1];
		printf("%lld\n",ways);
		t--;
	}
	return 0;    
}
