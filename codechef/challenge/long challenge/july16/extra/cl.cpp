#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define big 1000000009
int cost[502][502];
int costorder[502][502],tempc[502];
int mincost=big;
long long int factor[502]={0};
struct bat
{
    int snode;
    int power;
};
struct bat batch[502][502];
int main()
{
    long long int n,m,b,c,totaluf=0; //500 , 125 10^6
	scanf("%lld%lld%lld%lld",&n,&m,&b,&c);
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            //tempc[j-1]=j;
            if(i!=j)
            {
                if(cost[i][j]<mincost)
                {
                    mincost=cost[i][j];
                }
            }
        }
        /*
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n-1;k++)
            {
                if(cost[i][tempc[k]]>cost[i][tempc[k+1]])
                {
                    int temp=tempc[k];
                    tempc[k]=tempc[k+1];
                    tempc[k+1]=temp;
                }
            }
        }
        costorder[i][1]=i;
        for(int j=2;j<=n;j++)
        {
            costorder[i][j]=tempc[j-1];
        }*/
    }
   /* for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<costorder[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int dist[502][502];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = cost[i][j];
    for (int k= 1; k <=n ; k++)
    {
        for (int i = 1; i <=n; i++)
        {
            for (int j = 1; j <=n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
        //    cout<<dist[i][j]<<" ";
            tempc[j-1]=j;
        }
      //  cout<<endl;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n-1;k++)
            {
                if(dist[i][tempc[k]]>dist[i][tempc[k+1]])
                {
                    int temp=tempc[k];
                    tempc[k]=tempc[k+1];
                    tempc[k+1]=temp;
                }
            }
        }
        costorder[i][1]=i;
        for(int j=2;j<=n;j++)
        {
            costorder[i][j]=tempc[j-1];
        }
    }




    int bqueue[502]={0};
    for(int i=1;i<=m;i++)
    {
        int cnt[502]={0},bnode[502]={0},bindex=0;
        for(int j=1;j<=b;j++)
        {
            scanf("%d%d",&batch[i][j].snode,&batch[i][j].power);
            cnt[batch[i][j].snode]++;
        }
        if(i==1)
        {
            for(int j=1;j<=b;j++)
            {
                int node=batch[i][j].snode;
                int power=batch[i][j].power;
                if(cnt[node]>1) 
                {
                    if(factor[node]==0)
                    {
                        bnode[j]=node;
                        factor[node]+=power;
                    }
                    else
                    {
                        bqueue[bindex++]=j;
                    }
                    continue;
                }    
                bnode[j]=node;
                factor[node]+=power;
            }
            for(int j=0;j<bindex;j++)
            {
                int bno=bqueue[j];
                int node=batch[i][bno].snode;
                int power=batch[i][bno].power;
                int minfactor=factor[node],pos=node;
                for(int k=2;k<=n;k++)
                {
                    int ind=costorder[node][k];
                    if(dist[node][ind]<=c && factor[ind]<minfactor)
                    {
                        minfactor=factor[ind];
                        pos=ind;
                    }
                }
                if(dist[node][pos]<=c)
                {
                    c-=dist[node][pos];
                    bnode[bno]=pos;
                    factor[pos]+=power;
                }
                else
                {
                    bnode[bno]=node;
                    factor[node]+=power;
                }
            }
        }
        else
        {
            for(int j=1;j<=b;j++)
            {
                int node=batch[i][j].snode;
                int power=batch[i][j].power;
                int minfactor=factor[node],pos=node;
                //cout<<"node=" <<node<<endl;
                //cout<<"power=" <<power<<endl;
                //cout<<"position=" <<pos<<endl;
                //cout<<"minfactor=" <<minfactor<<endl;
                for(int k=2;k<=n;k++)
                {
                    int ind=costorder[node][k];
                    //cout<<"ind="<<ind<<endl;
                    if(dist[node][ind]<=c && factor[ind]<minfactor)
                    {
                        minfactor=factor[ind];
                        pos=ind;
                    }
                }
                //cout<<"position=" <<pos<<endl;
                if(dist[node][pos]<=c)
                {
                    c-=dist[node][pos];
                    bnode[j]=pos;
                    factor[pos]+=power;
                }
                else
                {
                    bnode[j]=node;
                    factor[node]+=power;
                }
            }
        }
        int mx=0,mn=big;
        for(int i=1;i<=n;i++)
        {
            if(factor[i]>mx) mx=factor[i];
            if(factor[i]<mn) mn=factor[i];
        }
       // cout<<"unloading factor= "<<mx-mn<<endl;
        totaluf+=mx-mn;
        for(int j=1;j<=b;j++)
        {
            printf("%d\n",bnode[j]);
        }
        fflush(stdout);
    }
   // cout<<"total unloading factor= "<<totaluf<<endl;
    return 0;
}
