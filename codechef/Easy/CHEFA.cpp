#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
    long long int a[100001]={0};
	while(t>0)
	{
	    long long int n,max=0;
		scanf("%lld",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        sort(a,a+n);
        for(int i=n-1;i>=0;i-=2)
        {
            max+=a[i];
        }
        printf("%lld\n",max);
		t--;
	}
	return 0;
}
