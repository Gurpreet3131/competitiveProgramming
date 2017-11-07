#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		int x, y; scanf("%d%d",&x,&y);
		int a = 0, b = 0;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == 'a') a++;
			else b++;
		}
		string ans = "";
		int minval = min(a, b);
		a-= minval; b-=minval;
		if(a == b)
		{
			for(int i = 0; i < minval; i++) ans+= 'a', ans+='b';
		}
		else if(a > b)
		{
			a--;
			if(a == 0)
			{
				for(int i = 0; i < minval; i++) ans+='a', ans+='b';
				ans+='a';
			}
			else 
			{
				for(int i = 0; i < minval; i++)
				{
					ans+='a';
					for(int j = 1; j < x;j++)
					{
						if(a == 0) break;
						a--; ans+='a';
					}
					ans+= 'b';
				}
				ans+='a';
				while(a > 0) ans+='a', a--;
			}
		}
		else
		{
			b--;
			if(b == 0)
			{
				for(int i = 0; i < minval; i++) ans+='b', ans+='a';
				ans+='b';
			}
			else 
			{
				for(int i = 0; i < minval; i++)
				{
					ans+='b';
					for(int j = 1; j < y;j++)
					{
						if(b == 0) break;
						b--; ans+='b';
					}
					ans+='a';
				}
				ans+='b';
				while(b > 0) ans+='b', b--;
			}
		}
		int cta = 0, ctb = 0;
		for(int i = 0; i < ans.length(); i++)
		{
			if(ans[i] == 'a')
			{
				ctb = 0;
				cta++;
				if(cta > x)
				{
					printf("*");
					cta = 1;
				} 
			}
			else
			{
				cta = 0;
				ctb++;
				if(ctb > y) 
				{
					printf("*");
					ctb = 1;
				}
			}
			cout << ans[i];
		}
		printf("\n");
	}
	return 0;
}