#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		long long int h,s;
		scanf("%lld%lld",&h,&s);
		double first,b,c,theta;
		c=(double)h;
		{
			    double vv=(4*s)/(c*c);
				theta=(asin((4*s)/(c*c)))/2;
				if(vv<0 || vv>1)
				{
					printf("-1\n");
				}
				else
				{
					first=c*sin(theta);
					b=c*cos(theta);
					double val[3];
					val[0]=first; val[1]=b; val[2]=c;
					sort(val,val+3);
					printf("%lf %lf %lf\n",val[0],val[1],val[2]);
				}
		}
		t--;
	}
    return 0;
}