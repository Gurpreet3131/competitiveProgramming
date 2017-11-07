#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,a, flag = 0, mina = INT_MAX, maxa = INT_MIN;
		scanf("%d",&n);
		m.clear();	
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a<mina) mina = a;
			if(a>maxa) maxa = a;
			m[a]++;
			if(m[a] > 1) flag = a;
		}
		if(flag > 0) printf("%d\n",flag);
		else
		{
			if(m[mina+1] == 1) printf("%d\n",maxa);
			else printf("%d\n",mina);
		}
	}
	return 0;
}