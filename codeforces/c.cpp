#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int ans = 0;
	if(n >= 3)
	{
		vector<int> vv;
		int ans = 0;
		int next = 2, pre = 1;
		vv.push_back(next); vv.push_back(pre);
		while(1)
		{
			next += 2; pre+= 2;
			if(n%2 == 1)
			{
				if(next - 1 > n) break;
				if(next == n + 1)
				{
					next--; pre--;
					vv.push_back(next);
					vv.push_back(pre);
					break;
				}
				else
				{
					vv.push_back(next);
					vv.push_back(pre);
					vv.push_back(pre-1);
					if(next == n)
					{	
						vv.push_back(n);
						break;
					}
				}
			}
			else
			{
				if(next > n) break;
				vv.push_back(next);
				vv.push_back(pre);
				vv.push_back(pre-1);
				if(next == n)
				{	
					vv.push_back(n);
					break;
				}
			}
		}
		ans = vv.size();
		cout << ans << endl;
		for(int i = 0; i < vv.size(); i++)
		{
			cout << vv[i] <<" ";
		}
		cout << endl;
	}
	else if(n == 2)
	{
		cout << "3\n";
		cout << "2 1 2\n";
	}
	
	return 0;
}