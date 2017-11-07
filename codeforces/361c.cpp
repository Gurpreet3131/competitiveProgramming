#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	long long int m,n;
	scanf("%lld",&m);
    int flag=0;
    for(long long int i=8;i<10001;i++)
    {
        long long int ways=0; 
        long long int j=1;
        while(1)
        {
            for(long long int k=2;;k++)
            {
                long long int value=pow(k,3)*j;
                if(value<=i)
                {
                    ways++;
                    if(ways>m) break;
                }
                else break;
            }
            j++;   
            if(j*8>i) break;
            if(ways>m) break;
         }
        if(ways==m){ n=i; flag=1; break; }
        else if (ways>m) break;
    }
    if(flag==1) printf("%lld\n",n);
    else printf("-1\n");
    return 0;
}
