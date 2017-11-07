#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
  	int n,a,*report; scanf("%d",&n);
    report=new int[n+1];
    report[0]=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        report[a]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(report[i]==0) printf("%d ",i);
    }
    printf("\n");
	return 0;
}
