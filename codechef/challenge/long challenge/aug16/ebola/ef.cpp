#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <map>
#define inf 1000000009
using namespace std;
int w[10001]={0};
int adj[10001][10001]={0};
int totaladj[10001]={0};
int main()
{
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
    aff[s]=1;
    int queue[10001]={0};
    int rear=0; 

    int stack[10001]={0}, top=0;
    queue[rear++]=s; 
    for(int i=1;i<=k;i++)
    {
        int pos=1;
        long long int max=0,flag=0;
        top=0;
        /*for(int j=1;j<=n;j++)
        {
            if(vdone[j]==0 && aff[j]==0)
            {
                if(w[j]>max) max=w[j],pos=j;
            }
        }*/
        for(int j=0;j<rear;j++)
        {
            int node=queue[j];
            for(int k=0;k<totaladj[node];k++)
            {
                int nod=adj[node][k];
                if(vdone[nod]==0 && aff[nod]==0)
                {
                    if(w[nod]>max) max=w[nod],pos=nod,flag=1;
                }
            }
        }
        if(flag==0)
        {
            max=0;
            for(int j=1;j<=n;j++)
            {
                if(aff[j]==0 && vdone[j]==0)
                {
                    if(w[j]>=max) max=w[j],pos=j;
                }
            }
        }
        vac[i]=pos; vdone[pos]=1;
        top=0;
        for(int j=0;j<rear;j++)
        {
            int node=queue[j];
            for(int k=0;k<totaladj[node];k++)
            {
                int nod=adj[node][k];
                if(vdone[nod]==0 && aff[nod]==0)
                {
                    stack[top++]=nod;
                    aff[nod]=1;
                }
            }
        }
        //cout<<i<<endl;
        for(int j=0;j<top;j++)
        {
            queue[j]=stack[j];
          //  cout<<queue[j]<<" ";
        }
        cout<<endl;
        rear=top;       
    }
    printf("%d\n",k);
    for(int i=1;i<=k;i++)
    {
        printf("%d ",vac[i]);
    }
    return 0;
}