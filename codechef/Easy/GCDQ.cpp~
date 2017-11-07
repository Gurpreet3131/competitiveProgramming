#include<iostream>
#include<stdio.h>
using namespace std;
int gcd(int a,int b)
{
        if (b==0)
        return a;
        else
        return gcd(b,a%b);
}
int main()
{
	int t,l,r,a[100001]={0},left[100001]={0},right[100001]={0};
     scanf("%d",&t);
	while(t>0)
	{
		int n,q; scanf("%d%d",&n,&q);
        
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);              
        }    
        left[1]=a[1];
        for(int i=2;i<=n;i++)
        {
            left[i]=gcd(left[i-1],a[i]);
        }   
        right[n]=a[n]; 
        for(int i=n-1;i>0;i--)
        {
            right[i]=gcd(a[i],right[i+1]);
        }
        for(int i=1;i<=q;i++)
        {
            int l,r; scanf("%d%d",&l,&r);            
            if(l==1) printf("%d\n",right[r+1]);
            else if(r==n) printf("%d\n",left[l-1]);           
            else printf("%d\n",gcd(left[l-1],right[r+1]));  
        }        
        t--;        
	}
	return 0;
}
