#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
   	int t;  scanf("%d",&t);
    while(t>0)
    {
        long long int k,n,c,teach;
		scanf("%lld%lld",&n,&k);
        if(k==0)
        {
           c=0;teach=n;
        }
		else 
        {
            c=n/k; teach=n%k;
        }
        printf("%lld %lld\n",c,teach);        
        t--;
    }
	return 0;
}
