#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define mod 786433
long long int a[250005]={0};
long long int ans[786434]={0};
long long int A[502][502]={0};
long long int X[25002][502]={0};
long long int Y[502][25002];
int main()
{
    int n,q;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    long long int sq=sqrt(n),mulsq=0,i=1,j=-1,x;
    long long int nn;
    if(sq*sq!=n)
    {
        sq++;
        nn=sq*sq;
    }
    else nn=n;
    //cout<<"nn="<<nn<<endl;
    while(j<=nn)
    { 
        for(j=mulsq*sq+1;j<=(mulsq+1)*sq;j++)
        {
            int ind=j%sq;
            if(ind==0) ind=sq;
            //cout<<i<<" j= "<<ind<<endl;
            A[i][ind]=a[j];
//            cout<<A[i][ind]<<" ";
        }
        mulsq++;
  //      cout<<endl;
        i++;
    }
    scanf("%d",&q);
    for(int z=1;z<=q;z++)
    {
        scanf("%lld",&X[1][z]);
        //printf("%lld\n",ans[x]);
    }
    //cout<<sq<<" "<<q<<endl;
    //cout<<"X=\n";
    for(int i=2;i<=sq;i++)
    {
        for(int j=1;j<=q;j++)
        {
            //cout<<i<<" "<<j<<endl;
            X[i][j]=X[i-1][j]*X[1][j];
            if(X[i][j]>=mod) X[i][j]%=mod;
    //        cout<<X[i][j]<<" ";
        }
      //  cout<<endl;
    }
    //cout<<"y=\n";
    for(int i=1;i<=sq;++i)
    {
        for(int j=1;j<=q;++j)
        {
            Y[i][j]=0;
            for(int k=1;k<=sq;++k)
               { Y[i][j]=Y[i][j]+(A[i][k]*X[k][j]);
                    //cout<<i<<" "<<k<<endl;
                    //cout<<"a[i][k]= "<<A[i][k]<<"  X[k][j]= "<<X[k][j]<<endl;
                    if(Y[i][j]>=mod) Y[i][j]%=mod;
                }
        //    cout<<Y[i][j]<<" ";
        }
      //  cout<<"\n";
    }
    //cout<<q<<endl;
    for(int j=1;j<=q;j++)
    {
        //cout<<"j= "<<j<<endl;
        long long int answer=a[0]+Y[1][j];
        long long int val=0,x=X[1][j];
        for(int k=2;k<=sq;k++)
        {
            val+=Y[k][j]*pow(x,(k-1)*sq);
            if(val>=mod) val%=mod;
        }
        answer+=val;
        answer%=mod;
        printf("%lld\n",answer);

    }
    return 0;
}
