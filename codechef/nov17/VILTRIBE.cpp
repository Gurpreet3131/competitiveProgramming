#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;  cin >>s;
		int cta = 0, ctb = 0, flag = 0;
		int cur = 0, ind;
		for(int i = 0; i < s.length(); i++)
		{
			if(flag == 0)
			{
				if(s[i] == 'A') cur = 1, ind = i, flag = 1, cta++;
				else if(s[i] == 'B') cur = 2, ind = i, flag = 1, ctb++;
			}
			else
			{
				if(s[i] == 'A')
				{
					if(cur == 1) 
					{
						cta += i - ind;
						ind = i;
					}
					else
					{
						cur = 1; cta++; 
						ind = i;
					}
				}
				else if(s[i] == 'B')
				{
					if(cur == 2)
					{
						ctb += i - ind;
						ind = i;
					}
					else 
					{
						cur = 2; ctb++;
						ind = i;
					}
				}
			}
		}
		cout << cta << " " << ctb << endl;
	}
    return 0;
}
