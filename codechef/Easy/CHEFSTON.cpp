#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
		int n;
        long long int k,a[100000],b[100000]; scanf("%d%lld",&n,&k);
		for(int i=0;i<n;i++)  scanf("%lld",&a[i]);
        for(int i=0;i<n;i++)  scanf("%lld",&b[i]);
        long long int max=(k/a[0])*b[0],earn=0;
        for(int i=1;i<n;i++)    
        {
            earn=(k/a[i])*b[i];
            if(earn>max) max=earn;
        }		
        printf("%lld\n",max);
        t--;
	}
	return 0;
}
