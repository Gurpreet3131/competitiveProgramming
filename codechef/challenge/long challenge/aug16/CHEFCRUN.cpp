#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#define inf 1000000009
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t-->0)
    {
        int n;
        scanf("%d",&n);
        long long int distc[n+2]={0},dista[n+2]={0};
        long long int weight[n+2]={0},sumall=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&weight[i]);
            sumall+=weight[i];
        }
        int start,end; scanf("%d%d",&start,&end);
        int count=1,index=start+1,dist=0;
        if(index == n+1) index = 1;
        distc[start]=0;
        while(count!=n)
        {
            if(index==n+1) index=1;
            if(index==1) dist+=weight[n];
            else dist+=weight[index-1];
            distc[index]=dist;
            count++;
            index++;
        }
        count=1; index=start-1; dist=0;
        dista[start]=0;
        while(count!=n)
        {
            if(index==0) index=n;
            if(index==n) dist+=weight[n];
            else dist+=weight[index];
            dista[index]=dist;
            count++;
            index--;
        }
        long long int minpath[n+2]={0};
        long long int ind=end-1,min=distc[end]-distc[ind];
        while(ind>start+1)
        {
            if(distc[end]-distc[ind] <=min)
            {
                min=distc[end]-distc[ind];
            }
            minpath[ind-1] = min;
            ind--;
        }
        ind=end+1; 
        if(ind==n+1) ind=1;
        min=dista[end]-dista[ind];
        while(ind>end || ind<start)
        {
            if(start==1 && ind==n) break;
            if(ind==start-1) break;
            if(dista[end]-dista[ind]<=min)
            {
                min=dista[end]-dista[ind];
            }
            if(ind==n) minpath[1] = min;
            else minpath[ind+1]=min;
            ind++;
            if(ind==n+1) ind=1;
        }
        long long int mindist;
        mindist= inf;
        count=0; index=start;
        while(count!=n)
        {
            if(index==n+1) index=1;
            if(start == index)
            {
                dist=distc[end]; if(dist<mindist) mindist=dist; 
                dist=dista[end]; if(dist<mindist) mindist=dist;
                dist=sumall+distc[end]; if(dist<mindist) mindist=dist; 
                dist=sumall+ dista[end]; if(dist<mindist) mindist=dist;
            }
            else if(index<end && index>start)
            {
                dist=2*distc[index]+dista[end]; 
                if(dist<mindist) mindist=dist;
                dist+=2*minpath[index];
                if(dist<mindist) mindist=dist;
                dist=dista[index]+(distc[end]-distc[index]);
                if(dist<mindist) mindist=dist;
                
            }
            else if(index>end || index<start)
            {
                dist=2*dista[index]+distc[end]; 
                if(dist<mindist) mindist=dist;
                dist+=2*minpath[index];
                if(dist<mindist) mindist=dist;
                dist=distc[index]+(dista[end]-dista[index]);
                if(dist<mindist) mindist=dist;   
            }
            index++; count++;
        }
        printf("%lld\n",mindist);
    }
    return 0;
}