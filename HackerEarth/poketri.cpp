#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <cmath>
using namespace std;
double area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
int main()
{
	int x1,x2,x3,y1,y2,y3; 
	scanf("%d%d",&x1,&y1);
	scanf("%d%d",&x2,&y2);
	scanf("%d%d",&x3,&y3);
	double a = area(x1,y1,x2,y2,x3,y3);
	double a1= area(x1,y1,x2,y2,0,0);
	double a2= area(x1,y1,0,0,x3,y3);
	double a3= area(0,0,x2,y2,x3,y3);
	if(a==0) printf("Invalid\n");
	else if(a1+a2+a3 == a) printf("Yes\n");
	else printf("No\n");
	return 0;
}