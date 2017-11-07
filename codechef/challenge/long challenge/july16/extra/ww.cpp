#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define mod 2520
long long int dp[20][512][2520]={0};
long long int maxk[512][2520]={0};
int main()
{
    
	int bin[512][10]={0};
    //setting mask for every set
    for(int i=1;i<512;i++)
    {
        int carry=0;
        for(int j=9;j>0;j--)
        {
            if(j==9) bin[i][j]=bin[i-1][j]+1+carry;
            else bin[i][j]=bin[i-1][j]+carry;
            if(bin[i][j]==2) carry=1,bin[i][j]=0;
            else carry=0;
        }
        /*if(i!=7) continue; 
        cout<<i<<" = ";
        for(int j=1;j<=9;j++)
        {
            cout<<bin[i][j];
        }
        cout<<endl;
        */
    }

    // setting maximum k value 
    for(int i=0;i<512;i++)
    {
        for(int j=9;j>0;j--) 
        {
            if(bin[i][j]==1)
            {
                for(int k=0;k<2520;k++)
                {
                    //if(i==7 && k<10) cout<<i<<" "<<k<<" "<<10-j<<" bin= "<<bin[i][j]<<endl;
                    if(k%(10-j)==0) maxk[i][k]++;
                }            
            }
        }
    }

// calcutaing 1 digit nmmbers 
    // i for mask, j for traversing the binary digits
    // one = number of one , k=remainder
    int queue[512]={0}, ind=0;
        for(int i=0;i<512;i++)
        {
            int one=0;
            for(int j=9;j>0;j--) 
            {
                if(bin[i][j]==1)
                {
                      one++;          
                }
            }
            if(one>1) continue;
         //   cout<<i<<"= ";
           // for(int j=1;j<=9;j++) cout<<bin[i][j];
            //cout<<endl;
            for(int k=1;k<=9;k++)
            {
                for(int j=9;j>0;j--) 
                {
                    if(bin[i][j]==1)
                    {
                        if(k==(10-j))
                        {
                            dp[1][i][k]++;
                            queue[ind++]=i;
                            //cout<<"i k dp[1][i][k]\n";
                            //cout<<i<<" "<<k<<" "<<dp[1][i][k]<<endl;
                        } 
                        break;
                    }
                }
            }
        }
    //for(int i=0;i<10;i++) cout<<i<<"= "<<maxk[7][i]<<endl;
    
    int preindex=ind;
    for(int dig=2;dig<19;dig++)
    {
        preindex=ind;
        for(int i=0;i<512;i++)
        {
            int one=0;
            for(int j=9;j>0;j--) 
            {
                if(bin[i][j]==1)
                {
                      one++;          
                }
            }
            if(one>dig) continue;
            queue[ind++]=i;
            for(int k=0;k<2520;k++)
            {
                for(int l=0;l<preindex;l++)
                {
                    dp[dig][i][(k*10+k%10)%2520]+=dp[dig-1][queue[l]][k];
                }

            }
        }
    }
    int q;
	scanf("%d",&q);
    while(q>0)
    {
        long long int l,r,kvalue,numcount=0,countl=0,countr=0;           
        scanf("%lld%lld%lld",&l,&r,&kvalue);
        long long int digr=0,tempr=r,digl=0,templ=l;
        while(tempr>0)
        {
            tempr/=10; digr++;
        }
        while(templ>0) templ/=10,digl++;
        for(int dig=1;dig<=digr;dig++)
        {

            for(int i=0;i<512;i++)
            {
                int one=0;
                for(int j=9;j>0;j--) 
                {
                    if(bin[i][j]==1)
                    {
                          one++;          
                    }
                }
                if(one>dig) continue;
                for(int k=0;k<2520;k++)
                {
                    if(maxk[i][(k*10+k%10)%mod]>=kvalue)
                    {
                        countr+=dp[dig][i][k];
                    }
                }
            }
        }
        for(int dig=1;dig<=digl;dig++)
        {
            for(int i=0;i<512;i++)
            {
                int one=0;
                for(int j=9;j>0;j--) 
                {
                    if(bin[i][j]==1)
                    {
                          one++;          
                    }
                }
                if(one>dig) continue;
                for(int k=0;k<2520;k++)
                {
                    if(maxk[i][(k*10+k%10)%mod]>=kvalue)
                    {
                        countl+=dp[dig][i][k];
                    }
                }
            }
        }
        cout<<countr<<" "<<countl<<endl;
        numcount=countr-countl;
        printf("%lld\n",numcount);
        q--;
    }

    return 0;
}
