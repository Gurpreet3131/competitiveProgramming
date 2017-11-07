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
            if(i!=j)
            {
                if(cost[i][j]<mincost)
                {
                    mincost=cost[i][j];
                }
            }
        }
    }
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
            tempc[j-1]=j;
        }
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
        int bnode2[502]={0},bnode1[502]={0},bindex=0;
        for(int j=1;j<=b;j++)
        {
            scanf("%d%d",&batch[i][j].snode,&batch[i][j].power);
        }
        /*if(i==1)
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
        else*/
        int fac1[501]={0},fac2[501]={0};
        long long int cost1=c,cost2=c;
        for(int j=1;j<=n;j++)
        {
            fac1[j]=factor[j];
            fac2[j]=factor[j];
        }
        int maxdif;
        {
            for(int j=1;j<=b;j++)
            {
                bqueue[bindex++]=j;
            }
            for(int j=0;j<bindex;j++)
            {
                for(int k=0;k<bindex-1;k++)
                {
                    if(batch[i][bqueue[k]].power<batch[i][bqueue[k+1]].power)
                    {
                        int temp=bqueue[k];
                        bqueue[k]=bqueue[k+1];
                        bqueue[k+1]=temp;
                    }
                }
            }
            for(int j=0;j<bindex;j++)
            {
                int bno=bqueue[j];
                int node=batch[i][bno].snode;
                int power=batch[i][bno].power;
                int minfactor=fac1[node],pos=node;
                for(int k=2;k<=n;k++)
                {   
                    int ind=costorder[node][k];
                    if(dist[node][ind]<=cost1 && fac1[ind]<minfactor)
                    {
                        minfactor=fac1[ind];
                        pos=ind;
                    }
                }
                if(dist[node][pos]<=cost1)
                {
                    cost1-=dist[node][pos];
                    bnode1[bno]=pos;
                    fac1[pos]+=power;
                }
                else
                {
                    bnode1[bno]=node;
                    fac1[node]+=power;
                }
            }
        }
        int maxp=-1,minp=big;
        for(int j=1;j<=n;j++)
        {
            if(fac1[j]>maxp) maxp=fac1[j];
            if(fac1[j]<minp) minp=fac1[j];
        }
        maxdif=maxp-minp;

        for(int j=1;j<=b;j++)
            {
                int node=batch[i][j].snode;
                int power=batch[i][j].power;
                int minfactor=fac2[node],pos=node;
                //cout<<"node=" <<node<<endl;
                //cout<<"power=" <<power<<endl;
                //cout<<"position=" <<pos<<endl;
                //cout<<"minfactor=" <<minfactor<<endl;
                for(int k=2;k<=n;k++)
                {
                    int ind=costorder[node][k];
                    //cout<<"ind="<<ind<<endl;
                    if(dist[node][ind]<=cost2 && fac2[ind]<minfactor)
                    {
                        minfactor=fac2[ind];
                        pos=ind;
                    }
                }
                //cout<<"position=" <<pos<<endl;
                if(dist[node][pos]<=cost2)
                {
                    cost2-=dist[node][pos];
                    bnode2[j]=pos;
                    fac2[pos]+=power;
                }
                else
                {
                    bnode2[j]=node;
                    fac2[node]+=power;
                }
            }
            maxp=-1; minp=big;
            for(int j=1;j<=n;j++)
            {
            if(fac2[j]>maxp) maxp=fac1[j];
            if(fac2[j]<minp) minp=fac1[j];
            }
            int flag=0;
            if(maxdif>=(maxp-minp)) flag=1;
            else flag=2;
            if(flag==1)
            {
                c=cost1;
                for(int j=1;j<=n;j++)
                {
                    factor[j]=fac1[j];
                }
            }
            else
            {
                c=cost2;
                for(int j=1;j<=n;j++)
                {
                    factor[j]=fac2[j];
                }
            }
        for(int j=1;j<=b;j++)
        {
            if(flag==1) printf("%d\n",bnode1[j]);
            else printf("%d\n",bnode2[j]);
        }
        fflush(stdout);
    }
    return 0;
}
