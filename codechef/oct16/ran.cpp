#include <bits/stdc++.h>
using namespace std;
int num = 100000;
int main()
{
	srand(time(NULL));
	int t=1; cout<<t<<endl;
	int n=5,m=40;
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++)
	{
		int a = 1+ rand()%num;
		cout<<a<<" ";
	} 
	cout<<endl;
	for(int i=1;i<=m;i++)
	{
		int type,l,r; 
		type = 1+rand()%3;
		l = 1+rand()%5;
		r = rand()%(n-l+1);
		r = l+r;
		cout<<type<<" "<<l<<" "<<r<<" ";
		if(type == 1)
		{
			long long int x = 1+rand()%num;
			cout<<x<<endl;
		}
		else if(type==2)
		{
			long long int y = 1+rand()%num;
			cout<<y<<endl;
		}
		else cout<<endl;
	}
	return 0;
}