#include<bits/stdc++.h>
#include<string.h>
#define big 1000000005
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n;
		scanf("%d",&n);
		if(n%6==0) printf("Misha\n");
		else printf("Chef\n");
		t--;
	}
	return 0;
}