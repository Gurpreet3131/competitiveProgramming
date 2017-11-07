#include <bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(NULL));
	int n, q;
	n = 10;
	q = 50;
	cout << n << " " << q << endl;
	for(int i = 0; i < n; i++)
	{
		int val = rand()% 10;
		int sign = rand() % 2;
		if(sign == 0) val = -val;
		cout << val << " ";
	}
	cout << endl;
	for(int i = 0; i < n; i++)
	{
		int val = rand()% 10;
		int sign = rand() % 2;
		if(sign == 0) val = -val;
		cout << val << " ";
	}
	cout << endl;
	while(q--)
	{
		int type, a, b;
		type = 1 + rand() % 3;

		if(type <= 2)
		{
			a = 1 + rand() % n;
			int val = rand()% 10;
			int sign = rand() % 2;
			if(sign == 0) val = -val;
			b = val;
		}
		else
		{
			int val = 1 + rand()% (n - 1);
			a = val;
			b = a + rand() % n;
			b = min(b, n);
		}
		cout << type << " " << a << " " << b << endl;
	}
	return 0;
}