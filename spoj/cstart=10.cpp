#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		double u, v, w, U, V, W;
		//cin >> u >> w >> V >> v >> W >> U;
		cin >> u >> v >> w >> W >> V >> U;
		double ud = pow(v, 2) + pow(w, 2) - pow(U, 2);
		double vd = pow(w, 2) + pow(u, 2) - pow(V, 2);
		double wd = pow(u, 2) + pow(v, 2) - pow(W, 2);
		double b = 12;
		//double par = (4*pow(u, 2)*pow(v, 2)*pow(w, 2)) - (pow(u, 2)*pow(ud, 2)) - (pow(v, 2)*pow(vd, 2)) - (pow(w, 2)*pow(wd, 2)) + (ud*vd*wd);
		double par =4*(pow(u,2)*pow(v,2)*pow(w,2)) - pow(u,2)*pow((pow(v,2)+pow(w,2)-pow(U,2)),2) - pow(v,2)*pow((pow(w,2)+pow(u,2)-pow(V,2)),2) - pow(w,2)*pow((pow(u,2)+pow(v,2)-pow(W,2)),2) + (pow(v,2)+pow(w,2)-pow(U,2))*(pow(w,2)+pow(u,2)-pow(V,2))*(pow(u,2)+pow(v,2)-pow(W,2));

		double vol = sqrt(par);
		vol /= b;
		printf("%.4lf\n", vol);
	}
	return 0;
}