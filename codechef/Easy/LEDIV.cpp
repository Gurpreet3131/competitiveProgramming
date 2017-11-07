#include<iostream>
#include<stdio.h>
#include<string.h>
#define mod 10000009
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
	    int n,a[100001],min=1000004,found=1,even=1; scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(min>a[i]) min=a[i];
            if(a[i]%2!=0) even=0;
        }
        if(even==1)
        {
            min=2;
        }
        else
        {
            for(int i=3;i<=min;i+=2)
            {
                found=1;
                for(int j=0;j<n;j++)
                {
                    if(a[j]%i!=0) 
                    {
                        found=0; break;
                    }
                }
               if(found==1) break;
            }
            if(found==0) min=-1;
        }
        printf("%d\n",min);
		t--;
	}     
	return 0;
}
