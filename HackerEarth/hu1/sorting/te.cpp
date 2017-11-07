#include <bits/stdc++.h>
using namespace std;
int a[10000001];
int main()
{
	int n; cin>>n;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}