#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int y, x1, x2;
		cin >> y >> x1 >> x2;
		y = (y<0?-y:y);
		int f[20], k = 0;
		for(int i = 2; i*i <= y; i++) if(y%i == 0)
		{
			f[k++] = i;
			while(y%i == 0)
				y /= i;
		}
		if(y > 1) f[k++] = y;
		int c1 = 0, c2 = 0;
		int s1 = 1, s2 = 1;
		if(x1 < 0) { x1 = -x1; s1 = -1;}
		else if(x1) x1--;
		if(x2 < 0) { x2 = -x2; x2--; s2 = -1;}
		for(int i = 0; i < (1<<k); i++)
		{
			int s = 1, p = 1;
			for(int j = 0; j < k; j++) if(i&(1<<j))
			{
				s *= -1;
				p *= f[j];
			}
			c1 += s*(x1/p);
			c2 += s*(x2/p);
		}
		cout << (s2*c2)-(s1*c1) << endl;
	}
	return 0;
}