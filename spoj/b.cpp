#include <bits/stdc++.h>
using namespace std;

double ncr(int n, int r)
{
	int power = n;
	double num = n, den = r, ans = 1.0;
	for(int i = 1; i <= r; i++)
	{
		ans *= (num / den);
		num -= 1.0; den -= 1.0;
	}
	for(int i = 1; i <= n; i++)
	{
		ans /= 2.0;
	}
	//cout << ans << endl;
	return ans;
}
int main()
{
	int t; cin >> t;
	while(t--)
	{
		double n; cin >> n;
		int ct = 0;

		for(int i = 0; i < n; i++)
		{
			int a; cin >> a;
			if(i > 0 && a == -1) ct++;

		}
		double ans;
		ans=(double)1;
		int temp  = ct;
        while(ct--)
        {
            ans=((double)(2*ans+1)/(double)(2));
        }
        cout<<setprecision(9)<<fixed<<(double)ans<<endl;
	
		ct = temp;
		if(ct == 0)
		{
			ans = 1.0;
			printf("%.11lf\n", ans);
			continue;
		}
		if(ct % 2 == 0)
		{
			ans = ct + 2.0;
			ans -= ncr(ct, ct / 2) * (ct / 2 + 1);
		}
		else //even terms
		{
			ans = (ct + 2.0) / 2.0;
		}
		//cout << ans << endl;
		printf("%.11lf\n", ans);
	}
	return 0;
}