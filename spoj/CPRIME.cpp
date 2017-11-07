#include <bits/stdc++.h>
using namespace std;
const int size = 100000001;
bool p[100000001];
int dp[100000001];
int main()
{
	p[0] = 1; p[1] = 1;
	for(int i = 2; i * i < size; i++)
	{
		if(p[i] == 0)
		{
			for(int j = i * 2; j < size; j+= i)
			{
				p[j] = 1;
			}
		}
	}
	for(int i = 1; i < size; i++)
	{
		if(p[i] == 0) dp[i] = 1 + dp[i - 1];
		else dp[i] = dp[i - 1];
	}
	int n; cin >> n;
	while(n != 0)
	{
		double pix = dp[n];
		double est = (double)n / log((double)n);
		//cout << pix << " " << est << endl;
		double ans = fabs(pix - est) * 100 / pix;
		printf("%.1lf\n", ans); 
		scanf("%d",&n);
	}
	return 0;
}