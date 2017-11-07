#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
    int order[401];
    while(t>0)
    {
        int n,m,occ=0;
        scanf("%d%d",&n,&m);
        int countleft[401]={0};
        for(int i=0;i<m;i++)
        {
            scanf("%d",&order[i]);
            countleft[order[i]]++;
        }
        
        t--;
    }

    return 0;
}
