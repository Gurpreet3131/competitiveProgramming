#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

    int main()
    {
        int t,N;
	scanf("%d",&t);
	int n=5000001;	
	int *a=new int[n];
        for(int i=1;i<2237;i++)
        {
            for(int j=i+1;j<2237;j+=2)
            {
                if(j%i==0 && i!=1) continue;
                int num=(i*i)+(j*j);
                for(int k=1;k*num<5000001;k++)
                {
                    a[num*k]=1;
                }
            }
        }
        while(t>0)
        {
            scanf("%d",&N);
	    if(a[N]==1) printf("YES\n");
	    else printf("NO\n");
            t--;
        }        
	return 0;
        
    }



