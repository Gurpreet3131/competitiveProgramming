#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define big 1000000009
long long int factor[501]={0};
int dist[501][501];
struct bat
{
    int snode;
    int power;
};
struct bat batch[501];
int main()
{
    long long int n,m,b,c,totaluf=0; //500 , 125 10^6
    scanf("%lld%lld%lld%lld",&n,&m,&b,&c);   
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&dist[i][j]);
        }
    }
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
    int bqueue[502]={0};
    for(int i=1;i<=m;i++)
    {
        int bnode[502]={0},bindex=0;
        for(int j=1;j<=b;j++)
        {
            scanf("%d%d",&batch[j].snode,&batch[j].power);
        }
        {
            for(int j=1;j<=b;j++)
            {
                bqueue[bindex++]=j;
            }
            for(int j=0;j<bindex;j++)
            {
                for(int k=0;k<bindex-1;k++)
                {
                    if(batch[bqueue[k]].power<batch[bqueue[k+1]].power)
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
                int node=batch[bno].snode;
                int power=batch[bno].power;
                int minfactor=factor[node],pos=node;
                for(int k=1;k<=n;k++)
                {   
                    int ind=k;
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
        for(int j=1;j<=b;j++)
        {
            printf("%d\n",bnode[j]);
        }
        fflush(stdout);
    }

    return 0;
}
