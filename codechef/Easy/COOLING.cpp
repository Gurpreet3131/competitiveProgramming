#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
	int main()
    {
        int t;
	scanf("%d",&t);
        while(t>0)
        {
            int N,*pies,*racks;  scanf("%d",&N);
            pies=new int[N];
            racks=new int[N];
            for(int i=0;i<N;i++)
            {
                scanf("%d",&pies[i]);
            }
            for(int i=0;i<N;i++)
            {
                scanf("%d",&racks[i]);
            }
            sort(pies,pies+N);
            sort(racks,racks+N);
            int count=0,start=0;
            for(int i=0;i<N;i++)
            {
                    if(pies[i]<=racks[start])
                    {
                        count++;
                    }
                    else
                    {
                        i--;
                    }
                    start++;
                    if(start==N) break;
            }
            printf("%d\n",count);
            t--;
	 }
        return 0;
    }


