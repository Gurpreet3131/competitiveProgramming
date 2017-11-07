#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <time.h>
#include <vector>
#include <queue>
#include <cmath>
#define mod 1000000009
using namespace std;
int n;
struct c
{
    double xc;
    double yc;
    double rc;
};

void check()
{
    return;
}
//few functions taken from internet
double section(double h, double r = 1) 
{
    if(h<r) return sqrt(r * r - h * h);
    else return 0.0;
}
double integrate(double x, double h, double r = 1) 
{
    double val= 0.5 * (sqrt(1 - x * x / (r * r)) * x * r + r * r * asin(x / r) - 2 * h * x); 
    return val;
}
double area2(double x0, double x1, double h, double r) 
{
    check();
    double s = section(h, r);
    return integrate(max(-s, min(s, x1)), h, r) - integrate(max(-s, min(s, x0)), h, r); 
}
double area(double x0, double x1, double y0, double y1, double r) 
{
    check();
    if(y0 > y1)
        swap(y0, y1); 
    if(y0 < 0) 
    {
        check();
        if(y1 < 0) return area(x0, x1, -y0, -y1, r); 
        else return area(x0, x1, 0, -y0, r) + area(x0, x1, 0, y1, r); 
    } 
    else return area2(x0, x1, y0, r) - area2(x0, x1, y1, r); 
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
    c circle[50002]; 
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf%lf",&circle[i].xc,&circle[i].yc,&circle[i].rc);
    }  
    double x1,y1,x2,y2;
    for(int i=0;i<q;i++)
    {
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        double inarea=0;        
        for(int i=0;i<n;i++)
        {
            double xc=circle[i].xc,yc=circle[i].yc,rc=circle[i].rc;
            inarea+=area(x1-xc,x2-xc,y1-yc,y2-yc,rc);
        }
        printf("%lf\n",inarea);
    }
	return 0;
}