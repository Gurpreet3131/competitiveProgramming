#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
   	long long int n;  scanf("%lld",&n);
    long long int sum=0,total=(n*(n+1))/2;
    
    while(n>0)
    {
        long long int num;
		scanf("%lld",&num);
        sum+=num;
        n--;
    }
    if(sum==total) printf("YES\n"); 
    else printf("NO\n");
	return 0;
}
