#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	int a[n];
	int one[n+1] = {0};
	for(int i = 0 ; i< n; i++)
	{
		cin >> a[i];
	}
	for(int i = n - 1; i >=0; i--)
	{
		one[i] = one[i+1] + a[i]; 
	}
	int ct = 0, mx = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == 0) 
		{
			ct++;
			mx = max(mx, ct + one[i+1]);
		}
		else mx = max(mx, ct + one[i]);
	}
	cout << mx << endl;
	return 0;
}