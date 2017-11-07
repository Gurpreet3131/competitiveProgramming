#include <bits/stdc++.h>
using namespace std;
#define nmod 500
string s[502];

int main()
{
	srand(time(NULL));
	int n,m;
	n = rand()%nmod;
	m = rand()%nmod;
	cout<<n<<" "<<m<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int r = rand()%2;
			if(r==0) cout<<"0";
			else cout<<"1";
		}
		cout << endl;
	}
	return 0;
}