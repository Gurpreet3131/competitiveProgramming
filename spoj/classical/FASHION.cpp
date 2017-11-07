#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,m[1001],w[1001]; scanf("%d",&t);
	while(t>0)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&m[i]);
		for(int i=0;i<n;i++) scanf("%d",&w[i]);
		sort(m,m+n);
		sort(w,w+n);
		int value=0;
		for(int i=0;i<n;i++)
		{
			value+=(m[i]*w[i]);
		}
		printf("%d\n",value);
		t--;
	}
	return 0;
}