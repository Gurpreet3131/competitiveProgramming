#include <bits/stdc++.h>
using namespace std;

void allStrings(int m, int n)
{
	//creating a of length n, all digits 0
	string s;
	for(int i = 0; i < n; i++)
		s += '0';

	// flag = 1 determines length has become n+1
	// i -> starts from end of string to start performing addition with 1
	int flag = 0, i = n - 1;
	while(flag == 0)
	{
		cout << s << endl; //printing the string
		i = n - 1;
		while(1) //till there is no carry or length <= n
		{
			s[i]++; // incrementing the last index
			// if s[i] > m, then make s[i] = 0 and make is one index to left
			// along with carry, otherwise break out of loop and print the string
			if((s[i] - '0') > m) s[i] = '0', i--; 
			else break;
			// if the length of string > n then make flag = 1 and break
			if(i < 0)
			{
				flag = 1; break;
			}
		}
	}
}
int main()
{
	int n,m; cin >> n >> m;
	allStrings(m, n);
	return 0;
}