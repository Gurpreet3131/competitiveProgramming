#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <map>
#define inf 1000000009
int w[10001]={0};
int adj[10001][10001]={0};
int totaladj[10001]={0},wst[10001]={0},pred[10001]={0};
std::map<int,int>m;
int main()
{
    srand(time(NULL));
    int n,m,k,s;
    scanf("%d%d%d%d",&n,&m,&k,&s);
    int tempk=k;
    for(int i=1;i<=n;i++) 
        scanf("%d",&w[i]);

    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u][totaladj[u]++]=v;
        adj[v][totaladj[v]++]=u;
        //adj[u][v]=1;
        //adj[v][u]=1;
    }
    int vac[505]={0},aff[10001]={0},vdone[10001]={0};
    aff[s]=1; pred[s]=-1;
    int queue[100001]={0};
    int rear=0; 
    int stack[100001]={0}, top=0,curtime=0,front=0;
    queue[rear++]=s; wst[s]=0;
    while(front<rear)
    {
        int node=queue[front++];
        for(int i=0;i<totaladj[node];i++)
        {
            int nod=adj[node][i];
            if(wst[nod]==0)
            {
                queue[rear++]=nod;
                wst[nod]=wst[node]+w[nod];
                pred[nod]=node;
            }
        }
    }
    int maxnode=0;
    for(int i=1;i<=n;i++)
    {
        if(wst[i]>maxnode) maxnode=wst[i];
    }
    int temp=maxnode,path[10001],index=0;
    while(temp!=s)
    {   
        path[index++]=temp;
        wst[temp]=0;
        temp=pred[temp];

    }
    index--;
    for(int i=1;i<=k;i++)
    {
        int pos=rand()%n,max=0;
        if(pos==0) pos=n;
        if(index>=0)
        {
            pos=path[index];
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                if(vdone[j]==0 && aff[j]==0)
                {
                    if(wst[j]>max) max=wst[j],pos=j;
                }
            }
        }
        vac[i]=pos; vdone[pos]=1;
    }
    printf("%d\n",k);
    for(int i=1;i<=k;i++)
    {
        printf("%d ",vac[i]);
    }
    return 0;
}