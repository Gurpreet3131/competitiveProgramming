#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int n,m;
		cin>>n>>m;
		if(n%2==0 || m%2==0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}