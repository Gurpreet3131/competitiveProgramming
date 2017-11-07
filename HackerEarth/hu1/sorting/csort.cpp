#include <bits/stdc++.h>
using namespace std;
int ct[1000001]={0};
int main()
{
	int n; cin>>n;
	int a;

	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		ct[a]++;
	} 
	for(int i=0;i<1000001;i++)
	{
		while(ct[i]-->0) printf("%d ",i);
	} 
	return 0;
}