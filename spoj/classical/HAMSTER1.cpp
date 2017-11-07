#include <bits/stdc++.h>
using namespace std;
const int size = 101;
int a[size];
int main()
{
	int t; scanf("%d", &t);
	double pi = 3.14159, g = 10.0;
	while(t--)
	{
		double v, k1, k2;
		scanf("%lf%lf%lf",&v,&k1,&k2);
		double alpha = (pi - atan(4*k1 / k2)) / 2;
		double Hmax = (v * v * sin(alpha) * sin(alpha)) / (2 * g);
		double HR = (v * v * sin(2*alpha)) / g; 
		double points = k1 * HR + Hmax * k2;
		printf("%.3lf %.3lf\n",alpha, points);		
	}
	return 0;
}