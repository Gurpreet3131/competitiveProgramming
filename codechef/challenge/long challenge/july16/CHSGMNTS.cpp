#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define mod 786433
int main()
{
    int t;
    scanf("%d",&t);
    int arr[1005];
    while(t>0)
    {
        int n;
        long long int pairs=0,tempp=0,pos,all=1,same=1;           
        scanf("%d",&n);
        int queue[1005]={0};
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(all==1)
            {
                for(int j=0;j<i;j++)
                {
                    if(arr[i]==arr[j])
                    {
                        all=0; break;
                    }
                }
            }
            if(i!=0 && same==1)
            {
                if(arr[i]!=arr[i-1]) same=0;
            }
        }
        int ct[1001]={0};
        int a=0,b=0,c=1,flag=1; 
        if(n==1) pairs=0;
        else if(all==1)
        {
            long long int temp=n-1;
            for(int i=1;i<n;i++)
            {
                pairs+=i*((temp*(temp+1))/2);
                temp--;
            }
        }
        else if(same==1) pairs=0;
        else
        {
            long long int dif=0,maxj=-1;
            while(a<=n-2)
            {
                maxj=-1;
                for(int i=c;i<n;i++)
                {
                    for(int j=a;j<i;j++)
                    {
                        if(arr[i]!=arr[j])
                        {
                            ct[j]++;
                            if(j>maxj) maxj=j;
                        }
                        else
                        {
                            for(int k=j;k<=maxj;k++)
                            {
                                if(ct[k]!=0)
                                {
                                    pairs+=(ct[k]*(ct[k]+1))/2;
                                    ct[k]=0;
                                }
                            }
                            maxj=j-1;
                            break;
                        }
                    }
                }
                for(int i=0;i<n;i++)
                {
                    if(ct[i]!=0)
                    {
                        pairs+=(ct[i]*(ct[i]+1))/2;
                        ct[i]=0;                          
                    }
                }
                a++;
                c++;
            }
        }
        printf("%lld\n",pairs);
        t--;
    }

    return 0;
}
