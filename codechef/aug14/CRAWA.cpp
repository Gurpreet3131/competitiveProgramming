#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
    while(t>0)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int flag=0;
        if(x==0 && y==0) flag=1;
        else if(x==1 && y==0) flag=1;
        if(x>0  && x%2==1)
        {
            if(y<=x+1 && y>=1-x) flag=1;
        }
        else if(x<=0  && x%2==0)
        {
            if(y<=-x && y>=x) flag=1;
        }
        if(y>0 && y%2==0)
        {
            if(x>=-y && x<=y-1) flag=1;
        }
        else if(y<=0 && y%2==0)
        {
            if(x>=y && x<=1-y) flag=1;
        }
        if(flag==1) printf("YES\n");
        else printf("NO\n");
        t--;
    }

    return 0;
}
