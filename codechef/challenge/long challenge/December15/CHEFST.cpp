#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int n; scanf("%d",&n);
	int a[n+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	int count=0,k=0,index=1;
	while(count!=n)
	{
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=0) index=i;
            break;
        }		
        while(true)
        {
            cout<<index<<" ";
            count++;
            int temp=index;            
            index=a[index];
            a[temp]=0;
            if(a[index]==0)
            {
                cout<<index<<endl;
                k++;
                break;
            }                    
        }
	}
	return 0;
}
