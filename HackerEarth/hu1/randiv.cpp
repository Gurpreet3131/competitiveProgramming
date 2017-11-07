#include <bits/stdc++.h>
using namespace std;
#define mod 1000000
#define mod2 10000000
int main()
{
	srand(time(NULL));
	int n = 1+rand()%mod;
	int m = 1+rand()%mod;

	cout<<n<<" "<<m<<endl;
	for(int i=0;i<n;i++)
	{
		int v = rand()%mod;
		cout << v << " ";
	}
	cout<<endl;
	while(m--)
	{
		int ind = 1+rand()%n;
		cout<<ind<<endl;
	}
	return 0;
}