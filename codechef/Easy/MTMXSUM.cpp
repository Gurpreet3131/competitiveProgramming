#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#define mod 1000000007
using namespace std;
int main()
{
    int n; scanf("%d",&n);
    long long int a[100001],b[100001],c[100001][100001];
    long long int sum=0,maxc=0;    
    //long long int maxsum[100001]={0};    
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=(a[i]*b[j])+(i*b[j])+(j*a[i])+(i*j);
            sum+=c[i][j];
            if(c[i][j]>maxc) maxc=c[i][j];
            if(sum>=mod) sum%=mod;                    
        }
    }
    if(maxc>=mod) maxc%=mod; 
    maxsum[1]=sum;
    printf("%lld ",maxsum[1]);
    sum=0;
    int k=2,max=0;
    while(k<=n)
    {
        int flag=0;
        int starti=0,startj=0;          
        while(flag==0)
        {
            max=0;                              
            int endi=starti+k,endj=startj+k;
            if(endi<n && endj<n)
            {
                for(int i=starti;i<endi;i++)
                {
                    for(int j=startj;j<endj;j++)
                    {
                        if(c[i][j]>max) max=c[i][j];       
                    }
                }
                maxsum[k]+=max; if(maxsum[k]>=mod) maxsum[k]%=mod;
                if(endj==n-1 && endi==n-1) 
                {
                    flag=1; break;
                }                
                startj++;
                if(startj==n)
                {
                    startj=0; starti++;
                }            
            }     
        } 
        printf("%lld ",maxsum[k]);
        k++;             
    }
    return 0;    
}











