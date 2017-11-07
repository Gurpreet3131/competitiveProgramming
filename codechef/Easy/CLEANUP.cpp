#include<iostream>
#include<stdio.h>
using namespace std;
	int main()
    {
        int t; scanf("%d",&t);
        while(t>0)
        {
            int n,m,*job,*chef,*asis;
			scanf("%d%d",&n,&m);
            job=new int[n+1];
			int j;
            for(int i=0;i<m;i++)
            {
				scanf("%d",&j);                
				job[j]=1;
            }
            chef=new int[n-m];
            asis=new int[n-m];
            int turn=0,chefindex=0,asisindex=0;
            for(int i=1;i<=n;i++)
            {
                if(job[i]==1) continue;
                if(turn==0)
                {
                    chef[chefindex]=i;
                    chefindex++;
                    turn=1;
                }
                else if(turn==1)
                {
                    asis[asisindex]=i;
                    asisindex++;
                    turn=0;
                }
            }
            if(chefindex==0)
            {
                printf("\n\n");
            }
            else
            {
                for(int i=0;i<chefindex;i++)
                {
                    printf("%d ",chef[i]);
                }
                printf("\n");
                if(asisindex==0)
                {
                    printf("\n");
                }
                else
                {
                    for(int i=0;i<asisindex;i++)
                    {
                        printf("%d ",asis[i]);
                    }
                    printf("\n");
                }
            }
            
            t--;
        }
       return 0;
    }


