#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <map>
#define inf 1000000009
int w[10001]={0};
int adj[10001][10001]={0};
int totaladj[10001]={0};
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
    aff[s]=1;
    int queue[100001]={0};
    int rear=0; 
    int stack[100001]={0}, top=0;
    queue[rear++]=s; 
    for(int i=1;i<=k;i++)
    {
        int pos=rand()%n;
        if(pos==0) pos=n;
        long long int max=0;
        for(int j=1;j<=n;j++)
        {
            if(aff[j]==0 && vdone[j]==0)
            {
                if(w[j]>max) max=w[j],pos=j;
                else if(w[j]==max)
                {
                    long long int sum=0,sum2=0;
                    for(int k=0;k<totaladj[pos];k++)
                    {
                        int nod=adj[pos][k];
                        if(vdone[nod]==0 && aff[nod]==0) sum+=w[nod];
                    }
                    for(int k=0;k<totaladj[j];k++)
                    {
                        int nod=adj[j][k];
                        if(vdone[nod]==0 && aff[nod]==0) sum2+=w[nod];
                    }
                    if(sum2>sum) pos=j;
                }
            }
        }
        vac[i]=pos; vdone[pos]=1;
        for(int z=0;z<rear;z++) 
        {
            int node = queue[z];
            for(int j=0;j<totaladj[node];j++)
            {
                int nn=adj[node][j];
                if(vdone[nn]==0 && aff[nn]==0)
                {
                    stack[top++]=nn;
                    aff[nn]=1;
                }
            }
        }
        for(int z=0;z<top;z++)
        {
            queue[z]=stack[z];
        }
        rear=top;       
    }
    printf("%d\n",k);
    for(int i=1;i<=k;i++)
    {
        printf("%d ",vac[i]);
    }
    return 0;
}