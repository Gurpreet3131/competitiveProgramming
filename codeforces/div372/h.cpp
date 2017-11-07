#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,c,a[100005];
	scanf("%d%d",&n,&c);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int ct=0;
	for(int i=n-1;i>=0;i--)
	{
		int dif=a[i]-a[i-1];
		if(dif<=c) ct++;
		else break;
	}
	printf("%d\n",ct+1);
	return 0;
}