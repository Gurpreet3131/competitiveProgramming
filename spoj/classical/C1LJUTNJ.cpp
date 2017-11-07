#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int m, n; cin >> m >> n;
	long long int a[n], total = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		total += a[i];
	}
	/*
	total -= m;
	long long int sum = 0;
	long long int d = total / n, r = total%n;
	for(int i = 0; i < n; i++)
	{
		if(i < r) sum += (d+1) * (d+1);
		else sum += d*d;
	}
	cout << sum << endl;*/
	sort(a,a+n);
	
	long long int cand = 0, i, flag = 0;
	for(i = n - 1; i >0; i--)
	{
		long long int dif = a[i] - a[i - 1], items = n - i;
		cand += dif * items;
		if(cand > m)
		{
			cand -= dif * items;
			m-= cand; flag = 1;
			long long int dd = m / items;
			
			a[i] -= dd; m-= items * dd;
			if(m > 0)
			{
				m--, a[i]--;
				for(int j = i+1; j < n; j++)
				{
					if(m > 0) a[j] = a[i], m--;
					else a[j] = a[i] + 1;
				}
			} 
			else
			{
				for(int j = i+1; j < n; j++)
				{
					a[j] = a[i];
				}
			}
			
			break;
		}
		else a[i] = a[i - 1];
	}
	if(flag == 0)
	{
		m-= cand;
		long long int dd = m / n;
		
		a[0] -= dd; m-= n * dd;
		if(m > 0)
		{
			m--, a[0]--;
			for(int j = 1; j < n; j++)
			{
				if(m > 0) a[j] = a[0], m--;
				else a[j] = a[0] + 1;
			}
		} 
		else
		{
			for(int j = 1; j < n; j++)
			{	
				a[j] = a[0];
			}
		}
		
	}
	long long int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += a[i] * a[i];
	}
	cout << sum << endl;
	return 0;
}