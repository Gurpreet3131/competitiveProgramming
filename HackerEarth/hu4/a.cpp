#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		long long int dif = fabs(a) + fabs(b);
		if(dif > k) printf("NO\n");
		else if(dif == k) printf("YES\n");
		else 
		{
			int f = fabs(dif - k);
			if(f%2==0) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}