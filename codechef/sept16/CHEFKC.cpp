#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <time.h>
#include <vector>
#include <queue>
#include <cmath>
#define mod 1000000009
using namespace std;
int adj[80][80]={0};
int n;
int main()
{
	int m,k;
	scanf("%d%d%d",&n,&m,&k);
    int s,t;
    scanf("%d%d",&s,&t);
    for(int i=0;i<m;i++)
    {   
        int u,v,wt;
        scanf("%d%d%d",&u,&v,&wt);
        adj[u][v]=wt;
    }
    int bit[n+1]={0},carry=0;
    int cut[100000]={0},cind=0;
    for(int i=0;i<=pow(2,n);i++)
    {
        if(bit[s]==bit[t]) 
        {
            carry=0;
            for(int j=1;j<=n;j++)
            {
                if(j==1)
                {
                    bit[j]+=1;
                    if(bit[j]==2) bit[j]=0,carry=1;
                    else break;
                }
                else
                {
                    bit[j]+=carry;
                    if(bit[j]==2) bit[j]=0,carry=1;
                    else break;
                }
            }
            continue;
        }
        vector<int> set1;
        vector<int> set2;
        for(int j=1;j<=n;j++)
        {
            if(bit[j]==bit[s]) set1.push_back(j);
            else if(bit[j]==bit[t])set2.push_back(j);
        }
        long long int sum=0;
        for(int u=0;u<set1.size();u++)
        {
            for(int v=0;v<set2.size();v++)
            {
                if(adj[set1[u]][set2[v]]>0)
                {
                    sum+=adj[set1[u]][set2[v]];
                }
            }
        }
        /* cout<<"sum= "<<sum<<endl;
            for(int u=0;u<set1.size();u++)
                cout<<set1[u]<<" ";
            cout<<endl;
            for(int u=0;u<set2.size();u++)
                cout<<set2[u]<<" ";
            cout<<endl;*/
        cut[cind++]=sum;
        carry=0;
        for(int j=1;j<=n;j++)
        {
            //cout<<j<<endl;
            if(j==1)
            {
                bit[j]+=1;
                if(bit[j]==2) bit[j]=0,carry=1;
                else break;
            }
            else
            {
                bit[j]+=carry;
                if(bit[j]==2) bit[j]=0,carry=1;
                else break;
            }
        }
    }
   // for(int i=0;i<cind;i++) cout<<cut[i]<<" ";
     //   cout<<endl;
    sort(cut,cut+cind);
    //for(int i=0;i<5;i++) cout<<cut[i]<<endl;    
    printf("%d\n",cut[2*(k-1)]);
	return 0;
}