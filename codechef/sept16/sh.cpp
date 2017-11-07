#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <time.h>
#include <vector>
#define mod 1000000009

using namespace std;
double PI = 3.14159;
struct Point 
{
    double x;
    double y;
};
vector<Point> polygon;
long long int fsum=0;
long long int f[100001]={0},n;
double angle2d(double x1,double y1,double x2, double y2)
{
    double dtheta,theta1,theta2;

    theta1 = atan2(y1,x1);
    theta2 = atan2(y2,x2);
    dtheta = theta2 - theta1;
    while (dtheta > PI)
         dtheta -= 2*PI;
    while (dtheta < -PI)
          dtheta += 2*PI;

   return(dtheta);
}
bool inpoint(double x, double y)
{
    bool in=false;
    double angle=0;

    for(int i=0;i<n;i++)
    {
        double x1,x2,y1,y2;
        x1=polygon[i].x-x;
        y1=polygon[i].y-y;
        x2=polygon[(i+1)%n].x-x;
        y2=polygon[(i+1)%n].y-y;
        angle+= angle2d(x1,y1,x2,y2);
    }
    if(fabs(angle)<PI) in=false;
    else in=true;
    return in;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t-->0)
    {
        long long int a,b,c,d;
        scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
        scanf("%lld%lld%lld%lld",&f[0],&f[1],&f[2],&f[3]);
        for(int i=4;i<2000;i++)
        {
            f[i]= (a*f[i-1])%mod;
            if(f[i]>=mod) f[i]%=mod;
            f[i]+= (b*f[i-2])%mod;
            if(f[i]>=mod) f[i]%=mod;
            f[i]+= (c*f[i-3])%mod;
            if(f[i]>=mod) f[i]%=mod;
            f[i]+= (d*f[i-4])%mod;
            if(f[i]>=mod) f[i]%=mod;
        }
        //Point polygon[n];
        long long int ymin=INT_MAX,ymax=INT_MIN;
        for(int i=0;i<n;i++)
        {
            Point pp;
            scanf("%lf%lf",&pp.x,&pp.y);
            polygon.push_back(pp);
        }
        fsum=0;
        for(int i=0;i<=4;i++)
        {
            for(int j=0;j<=4;j++)
            {
                Point p={(double)i,(double)j};
             //   cout<<"checking = "<<i<<" "<<j<<endl;
                bool in=inpoint((p.x),(p.y));
                if(in==true)
                {
                    cout<<"inside "<<i<<" "<<j<<endl;
                    fsum+=f[i+j];
                    if(fsum>=mod) fsum%=mod;
                }
            }
        }
       // cout<<"fsum= "<<fsum<<endl;
        printf("%lld\n",fsum);
        polygon.clear();
    }
    return 0;
}