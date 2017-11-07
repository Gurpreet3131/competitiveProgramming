#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int n; scanf("%d",&n);
	int a[1005];
    int p[1005][1005],end[n+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	int count=0,k=0,index=1,j=0;
	while(count!=n)
	{
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=0) 
            {   index=i;
                break;
            }        
        }		
        while(true)
        {            
            p[k][j]=index;
            count++;j++;
            int temp=index;            
            index=a[index];
            a[temp]=0;
            if(a[index]==0)
            {
                p[k][j]=index; 
                end[k]=j+1;                 
                j=0;
                k++;
                break;
            }                    
        }
	}
    cout<<k<<endl;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<end[i];j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
