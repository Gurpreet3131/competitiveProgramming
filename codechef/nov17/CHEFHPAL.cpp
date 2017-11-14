#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, a, anslen = 0;
		scanf("%d%d",&n, &a);
		string ans = "";
		if(n <= a)
		{
			for(int i = 0; i < n; i++)
			{
				ans += (char)(i + 'a');
			}
			anslen = 1;
		}
		else if(a == 1)
		{
			anslen = n;
			for(int i = 0; i < n; i++) ans += 'a';
		}
		else if(a == 2)
		{
			if(n<=4)
			{
				ans = "aab"; 
				if(n ==4) ans+='b';
				anslen = 2;
			}
			else if(n <= 8)
			{
				anslen = 3;
				if(n == 5) ans = "aaaba";
				else if(n == 6) ans = "aaabab";
				else if(n == 7) ans = "aaababb";
				else if(n == 8) ans = "aaababbb";
			}
			else
			{
				anslen = 4;
				ans = "aaaa";
			    int flag = 0;
    			for(int i = 4; i < n; i++)
	    		{
		    	    if(flag == 0) ans += 'b', flag = 1;
        			else if(flag == 1) ans+='a', flag = 2;
			        else if(flag == 2) ans+='b', flag = 3;
			        else if(flag == 3) ans+='b', flag = 4;
			        else if(flag == 4) ans+='a', flag = 5;
			        else if(flag == 5) ans+='a', flag = 0;
			    }
			}
		}
		else
		{
			for(int i = 0; i < n; i++)
			{
				if(i % 3 == 0) ans += 'a';
				else if(i % 3 == 1) ans += 'b';
				else ans += 'c';
			}
			anslen = 1;
		}
		cout << anslen << " " << ans << endl;
	}
    return 0;
}
