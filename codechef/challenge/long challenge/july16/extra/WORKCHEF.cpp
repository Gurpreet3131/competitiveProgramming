#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define mod 786433
int ks[1000001]={0};
int digits(long long int n)
{
    int ct=0;
    while(n>0)
    {
        ct++;
        n/=10;
    }
    return ct;
}
long long int si[10][10000001]={0};
int main()
{
	int q;
	scanf("%d",&q);
    for(int i=1;i<10000001;i++)
    {
        int dig[10]={0},digcount=0;
        long long int temp=i;
        while(temp>0)
        {
            int r=temp%10;
            temp/=10;
            if(r!=0 && dig[r]==0)
            {
                if(i%r==0) dig[r]=1,digcount++;
            }
        }
        ks[i]=digcount;
        for(int j=0;j<=9;j++)
        {
            if(i==1)
            {
                si[0][i]=1;
                si[1][i]=1;
                break;
            }
            else
            {
                si[j][i]=si[j][i-1];
                if(j<=digcount) si[j][i]++;
            }
        }
        //if(i<=200 && i>=100) cout<<i<<" = "<<ks[i]<<endl;
        //if(ks[i]==7) cout<<i<<" = "<<ks[i]<<endl;
    }
    while(q>0)
    {
        long long int l,r,k,numcount=0;           
        scanf("%lld%lld%lld",&l,&r,&k);
        //if(k!=0)
        {
            int digl=digits(l),digr=digits(r);
            long long int minl=-1;
            if(k!=0) minl=pow(10,k-1);
            l=max(minl,l);
            if(digr<k)
            {
                numcount=0;
            }
            else
            {
                if(r<10000001)
                {
                    numcount=si[k][r]-si[k][l-1];
                }
                else{
                for(long long int i=l;i<=r;i++)
                {
                    if(i<10000001)
                    {
                        if(ks[i]>=k) numcount++;
                    }
                    else
                    {
                        int dig[10]={0},digcount=0;
                        long long int temp=i;
                        while(temp>0)
                        {
                            int r=temp%10;
                            temp/=10;
                            if(r!=0 && dig[r]==0)
                            {
                                if(i%r==0) dig[r]=1,digcount++;
                            }
                        }
                        if(digcount>=k) numcount++;
                    }
                }
                }
            }  
        }
        printf("%lld\n",numcount);
        q--;
    }

    return 0;
}
