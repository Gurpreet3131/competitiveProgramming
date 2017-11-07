#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
	    long long int n,m,a[7];
        long long int sum=0,count=0;
        scanf("%lld%lld",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        sort(a,a+n);
        for(int i=n-1;i>=0;i--)
        {
            sum+=a[i];
            count++;
            if(sum>=m) break;
        }
        if(sum<m) count=-1;
        printf("%lld\n",count);
		t--;
	}
	return 0;
}
