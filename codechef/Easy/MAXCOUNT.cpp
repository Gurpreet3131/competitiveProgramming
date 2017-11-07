#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
	int main()
    {
        int t; scanf("%d",&t);
        while(t>0)
        {
            int N,*a,*count;
			scanf("%d",&N);            
			a=new int[N];
            count=new int[10001];
            int max=0;
            for(int i=0;i<N;i++) 
            {
                scanf("%d",&a[i]);
                count[a[i]]++;
                if(a[i]>max)
                {
                    max =a[i];
                }
            }
            int number=0,countnum=0;
            for(int i=1;i<=max;i++)
            {
                if(i==1) 
                {
                    number=i; countnum=count[i];
                    continue;
                }
                if(countnum<count[i])
                {
                    countnum=count[i];
                    number=i;
                }
            }
            printf("%d %d\n",number,countnum);
            t--;
	 }
		return 0;        
    }


