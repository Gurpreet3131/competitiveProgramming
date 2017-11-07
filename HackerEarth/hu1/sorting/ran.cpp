#include <bits/stdc++.h>
using namespace std;
#define mod 1000000
#define mod2 10
int main()
{
	srand(time(NULL));
	int n = 5e5;
	cout<<n<<endl;
	for(int i=0;i<n;i++)
	{
		int v = rand()%mod;
		cout << v << " ";
	}
	return 0;
}