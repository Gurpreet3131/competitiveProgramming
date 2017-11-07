#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n, k, m; cin >> n >> k >> m;
	long long int a[k], mx = 0, sum = 0;
	for(int i = 0 ; i< k; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a,a+k);
 		long long int tempm = m;
 		for(long long int i = 0; i <= n; i++)
		{
			long long int temp = 0;
			m = tempm;
			// i completed tasks
			if(sum * i <= m) temp += i * (k+1), m-= sum*i;
			else break;

			for(long long int j = 0; j < k; j++)
			{
				if(m < a[j]) break;
				if((n - i) * a[j] <=m)
				{
					if(j == k - 1) temp += (n - i) + (n - i);
					else temp += (n - i);
					m -= (n - i) * a[j];
				}
				else
				{
					if(j == k - 1) temp += (m / a[j]) + (m / a[j]);
					else temp += m / a[j];
					m = 0;
				}
			}
			if(temp > mx) mx = temp;
		}	
	cout << mx << endl;
	return 0;
}