#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
	    int n,a[100001]; 
        int maxdif=0,mini=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
            if(i==0) mini=a[i];
            else 
            {
                maxdif=max(maxdif,a[i]-mini);
                mini=min(mini,a[i]);
            }		
        }
        if(maxdif>0) printf("%d\n",maxdif);     
        else printf("UNFIT\n");
		t--;
	}
	return 0;
}
