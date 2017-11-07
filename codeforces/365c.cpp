//incomplete

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#define min(a,b) a<b?a:b
using namespace std;
struct P
{
	int x;
	int y;
};
int main()
{
	long long int n,w,v,u;	
	scanf("%lld%lld%lld%lld",&n,&w,&v,&u);
	P point[10003];
	int lx,ly,ux,uy,dx,dy,rx,ry;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&point[i].x,&point[i].y);
		if(i==0)
		{
			lx = point[i].x;
			ly = point[i].y;
			ux=lx; rx=lx; dx=lx;
			uy=ly; ry=ly; dy=ly;
		}
		else
		{
			if(point[i].x < lx)
			{
				lx= point[i].x; ly = point[i].y;
			}
			if(point[i].x > rx)
			{
				rx= point[i].x; ry = point[i].y;
			}
			if(point[i].y > uy)
			{
				ux= point[i].x; uy = point[i].y;
			}
			if(point[i].y < dy)
			{
				dx= point[i].x; dy = point[i].y;
			}
		}
	}
	double tman=0,tbusa=0,tbusd=0;
	tman=((float)w)/u;
	tbusa = ((float)(lx+1)/v;
	tbusd = ((float)(rx))/v;
	if(tbusd<=0)
	{
		printf("%lf",tman);
	}
	else if(tbusa<=0 && tbusd)
	{

	}
	return 0;
}