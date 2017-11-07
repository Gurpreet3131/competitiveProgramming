#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	int a[100002];
	while(t-->0)
	{
		int n; scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		for(int i=0;i<n;i++) printf("%d ",a[i]);
		cout<<endl;		
	}	
	return 0;
}