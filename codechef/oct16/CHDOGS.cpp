#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		double s,v;
		scanf("%lf%lf",&s,&v);
		double tm = (2*s)/(3*v);
		printf("%lf\n",tm);
	}
	return 0; 
}