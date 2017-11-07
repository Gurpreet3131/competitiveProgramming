#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <time.h>
#include <vector>
#define mod 1000000009
#define val 200
using namespace std;
struct Point 
{
  	double x;
  	double y;
};
vector<Point> polygon;
long long int fsum=0;
long long int f[100001]={0},n;
bool inpoint(double x,double y)
{
  	int i, j;
  	bool in=false;
  	for (i = 0, j = n-1; i < n; j = i++) 
  	{
    if ( ((polygon[i].y>y) != (polygon[j].y>y)) &&
     (x < (polygon[j].x-polygon[i].x) * (y-polygon[i].y) / (polygon[j].y-polygon[i].y) + polygon[i].x) )
       in = !in;
  }
  return in;
}
long long int  area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2)));
}
bool checkon(double x,double y)
{
	bool in=false;
	for(int i=0;i<n;i++)
	{
		if(polygon[i].x==x && polygon[i].y==y)
		{
			in=true;
			break;
		}
	}
	//cout<<"in = "<<in<<endl;
	if(in==true) return in;
	else
	{
		int j=n-1;
		int x1,x2,y1,y2;
		int xx,yy;
		xx= (int)x; yy=(int)y;
		for(int i=0;i<n;i++)
		{
			x1=(int)polygon[j].x;
			y1=(int)polygon[j].y;
			x2=(int)polygon[i].x;
			y2=(int)polygon[i].y;
			long long int ta=area(xx,yy,x1,y1,x2,y2);
			if(ta==0)
			{
				if(xx>=min(x1,x2) && xx<=max(x1,x2))
				{
					if(yy>=min(y1,y2) && yy<=max(y1,y2))
					{
						in=true;
						break;
					}
				}
			}
			j=i;
		}
	}
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
		for(int i=0;i<=val;i++)
		{
			for(int j=0;j<=val;j++)
			{
				Point p={(double)i,(double)j};
				bool in=inpoint((p.x),(p.y));
				if(in==false)
				{
					//cout<<"checkon\n";
					in = checkon(p.x,p.y);
				}
				if(in==true)
				{
                   // cout<<"insdie= "<<i<<" "<<j<<endl;
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