#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int prime[309]={0},p[2050]={0},index=0; prime[0]=1; prime[1]=1;
    for(int i=2;i<2050;i++)
    {
        if(p[i]==0)
        {
            prime[index]=i; index++;
            for(int j=2;i*j<2050;j++)
            {
                p[i*j]=1;
            }
        }
    }	
    int t; scanf("%d",&t);
	while(t>0)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int sum=x+y;
        for(int i=0;i<index;i++)
        {
            if(sum<prime[i])
            {
                sum=prime[i]-sum;
                break;
            }
        }
        printf("%d\n",sum);
       	t--;
	}
	return 0;
}
