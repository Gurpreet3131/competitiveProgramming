#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, p; scanf("%d%d",&n,&p);
		int flag = 1;
		string ans = "";
		if(n <= 2) flag = 0;
		else if(p <= 2) flag = 0;
		else // n > 2 && p > 1 
		{
			if(n == p)
			{
				if(n % 2 == 1)
				{
					for(int i = 0; i < n; i++)
					{
						if(i%2 == 0) ans += 'a';
						else ans += 'b';
					}
				}
				else
				{
					for(int i = 1; i <= n / 2; i++)
					{
						if(i == n / 2) ans += 'b';
						else ans += 'a';
					}
					for(int i = 1; i <= n / 2; i++)
					{
						if(i == 1) ans += 'b';
						else ans += 'a';
					}
				}
			}
			else if(p % 2 == 1)
			{
				for(int i = 1; i <= n / p; i++)
				{
					for(int j = 0; j < p; j++)
					{
						if(j % 2 == 0) ans += 'a';
						else ans += 'b';
					}
				}
			}
			else //even period
			{
				// n is even
				//  8 4  abbaabba
				string temp = "";
				for(int i = 1; i <= p / 2; i++)
				{
					if(i == 1) temp += 'a';
					else temp += 'b';
				}
				for(int i = 1; i <= p / 2; i++)
				{
					if(i == p / 2) temp += 'a';
					else temp += 'b';
				}
				for(int i = 1; i <= n / p; i++)
				{
					ans += temp;
				}
			}
		} 
		if(flag == 1) cout << ans << endl;
		else printf("impossible\n");
	}
    return 0;
}
