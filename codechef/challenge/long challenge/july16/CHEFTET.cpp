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
    int a[10005],b[10005],temp[10005];
    while(t>0)
    {
        int n,big[5]={0},mx=0;
        int ind=0,maxa=0;  
        int flag=1,per=-1;         
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        for(int i=0;i<n;i++) 
        {
            scanf("%d",&a[i]);
            if(a[i]>maxa) maxa=a[i];
            temp[i]=a[i];
        }
        if(n==1) per=a[0]+b[0];
        else 
        {
            int a00=a[0]+b[0]; //20
            int a01=a[0]+b[1]; //14
            int a001=a[0]+b[0]+b[1]; //27
            
            if(a[0]>=maxa) big[ind++]=a[0];
            if(a00>=maxa) big[ind++]=a00;
            if(a01>=maxa) big[ind++]=a01;
            if(a001>=maxa) big[ind++]=a001;
            if(ind==0) per=-1;
            else
            {
                sort(big,big+ind);
                //for(int i=0;i<ind;i++) cout<<big[i]<<endl;
                for(int j=ind-1;j>=0;j--)
                {
                    mx=big[j]; flag=1;
                    //cout<<mx<<endl;
                    int used[10005]={0};
                    used[n]=1;
                    for(int i=0;i<n;i++)
                    {
                        if(i==0)
                        {
                            if(a[i]==mx)
                            {
                                a[i+1]+=b[i]; used[0]=1;
                                if(a[i+1]>mx) 
                                    {flag=0; break;}
                            } 
                            else if(a00==mx)
                            {
                                a[i]=a00; used[0]=1;
                            }
                            else if(a01==mx)
                            {
                                a[i]=a01; used[1]=1;
                                a[i+1]+=b[i]; used[0]=1;
                                if(a[i+1]>mx) 
                                    {flag=0;break;}
                            }
                            else if(a001==mx)
                            {
                                a[i]=a001; used[0]=1; used[1]=1;
                            }
                        }
                        else if(i==n-1)
                        {
                            if(used[n-2]==0) a[i]+=b[n-2];
                            if(used[n-1]==0) a[i]+=b[n-1];
                            if(a[i]!=mx)
                            {
                                flag=0; break;
                            }
                        }
                        else
                        {
                            if(used[i-1]==0) a[i]+=b[i-1];
                            if(a[i]>mx) {flag=0;break;}
                            else if(a[i]==mx) continue;
                            else
                            {
                                if(used[i]==0 && a[i]+b[i]==mx) 
                                    a[i]+=b[i],used[i]=1;
                                else if(used[i+1]==0 && a[i]+b[i+1]==mx) 
                                    a[i]+=b[i+1],used[i+1]=1;
                                else if(used[i]==0 && used[i+1]==0 && a[i]+b[i]+b[i+1]==mx) 
                                    a[i]+=b[i]+b[i+1],used[i]=1,used[i+1]=1;
                                else {flag=0;break;}     
                            }
                        }
                    }
                    for(int i=0;i<n;i++) a[i]=temp[i];
                    if(flag==1)
                    {
                        per=mx;
                        break;
                    }
                }
            }
            
        }
        printf("%d\n",per);
        t--;
    }

    return 0;
}
