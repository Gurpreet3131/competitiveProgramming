#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
    int n,cas=1;
    while(1)
    {
        long long int cof[1000]={0},sumall=0,x,value;
        scanf("%d",&n);
        if(n==-1) break;
        for(int i=n;i>=0;i--)
        {
            scanf("%lld",&cof[i]);
            sumall+=cof[i];
        }
        int k; scanf("%d",&k);
        printf("Case %d:\n",cas); cas++;
        for(int i=1;i<=k;i++)
        {
            scanf("%lld",&x);
            value=cof[n];
            for(int j=n-1;j>=0;j--)
            {
                value*=x;
                value+=cof[j];
            }
            printf("%lld\n",value);
        }
    }
    return 0;
}

