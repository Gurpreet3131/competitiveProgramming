#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,h; scanf("%d%d",&n,&h);
    int *stack;
    stack=new int[n];
    for(int i=0;i<n;i++) scanf("%d",&stack[i]);
    int cmd;
    scanf("%d",&cmd);
    int cpos=0,hold=0;
    while(cmd!=0)
    {
        switch(cmd)
        {
            case 1: if(cpos!=0) cpos--;
                    break;
            case 2: if(cpos!=n-1) cpos++; break;
            case 3: if(hold==0) 
                    {
                        if(stack[cpos]!=0)
                        {
                            hold=1;   
                            stack[cpos]--;
                        }
                    }                 
                    break;
            case 4: if(hold==1)
                    {
                        if(stack[cpos]!=h)
                        {
                            hold=0;   
                            stack[cpos]++;
                        }                       
                    }   
        }
        scanf("%d",&cmd);
    }
    for(int i=0;i<n;i++) printf("%d ",stack[i]);
	return 0;
}
