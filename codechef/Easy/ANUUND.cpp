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
        int n,a[100000]={0},temp=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			 scanf("%d",&a[i]);
			 if(i==0) continue;
			if((i-1)%2==0)
			{
				if(a[i-1]>a[i])
				{
					temp=a[i]; a[i]=a[i-1]; a[i-1]=temp;
				}
			}
			else
			{
				if(a[i-1]<a[i])
				{
					temp=a[i]; a[i]=a[i-1]; a[i-1]=temp;
				}
			}
			printf("%d ",a[i-1]);
		}	
		printf("%d\n",a[n-1]);
        t--;
    }
	return 0;
}
