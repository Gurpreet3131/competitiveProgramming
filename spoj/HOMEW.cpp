#include <bits/stdc++.h>
using namespace std;
const int size = 1000001;
typedef long long int lli;
lli a, b;
void calc(lli n)
{
	a = 1; b = 1;
	for(lli i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			lli ct = 0;
			while(n % i == 0)
			{
				n/=i, ct++;
				if(ct == 2)
				{
					a *= i; ct = 0;
				}
			}	
			if(ct == 1) b *= i;
		}
	}
	if(n > 1) 
	{
		b *= n;
	}
}

int main()
{
	lli n; cin >> n;
	while(n != -1)
	{
		calc(n);
		cout << a << " " << b << endl;
		cin >> n;
	}
	return 0;
}