#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
	int main()
    {
        int t; scanf("%d",&t);
        while(t>0)
        {
            int n,m,*notes;
			scanf("%d%d",&n,&m);
            notes=new int[n];
            int sum=0,sumall=0;
            for(int i=0;i<n;i++)
            {
                scanf("%d",&notes[i]);
                sumall+=notes[i];
            }
            if(sumall<m) 
            {
                printf("No\n");
                t--;continue;
            }
            if(sumall==m)
            {
                printf("Yes\n");
                t--;continue;
            }
            long int ilimit=(int)pow(2,n);
            for(int i=1;i<ilimit;i++)
            {
                sum=0;
                for(int j=0;j<n;j++)
                {
                    int set= ((i) & (1<<j));
                    if(set!=0)
                    {
                        sum+=notes[j];
                    }
                }
                if(sum==m)
                {
                    printf("Yes\n");
                    break;
                }
            }
            if(sum!=m) printf("No\n");
            t--;
	 }
       return 0;
    }


