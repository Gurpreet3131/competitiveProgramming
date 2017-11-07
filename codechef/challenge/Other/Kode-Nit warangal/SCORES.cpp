#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
		int n;scanf("%d",&n);
		int *a;
		a=new int[n];		
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		printf("%d %d\n",a[n-1],a[n-2]);
	
	return 0;
}
