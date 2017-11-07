#include<iostream>
#include<stdio.h>
using namespace std;
    int main()
    {
        int t,g,i,n,q;
	scanf("%d",&t);
        while(t>0)
        {
            scanf("%d",&g);
            while(g>0)
            {
		scanf("%d%d%d",&i,&n,&q);                
		int head=0,tail=0;
                if(n%2==0)
                {
                    head=(n/2);
                    tail=head;
                }
                else
                {
                    if(i==1)
                    {
                        tail=(n+1)/2;
                        head=n-tail;
                    }
                    else
                    {
                        head=(n+1)/2;
                        tail=n-head;
                    }
                }
                if(q==1) printf("%d\n",head);
                else printf("%d\n",tail);
                g--;
            }
            t--;
        }
    }


