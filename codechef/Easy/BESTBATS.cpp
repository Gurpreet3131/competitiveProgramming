#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	while(t>0)
	{
       	int k,a[11];
		for(int i=0;i<11;i++) cin>>a[i];
		sort(a,a+11);
		scanf("%d",&k);
		int sum=0,count=1,e=a[10];		
		for(int i=10;i>10-k;i--)
		{
			sum+=a[i];
			if(i==10) continue;
			if(a[i]==e) count++;
			else
			{
				count=1;
				e=a[i];
			}
		}
		for(int i=10-k;i>=0;i--)
		{
			if(a[i]==e) count++;
			else break;
		}
		int c2=0;
		for(int i=0;i<11;i++)
		{
				if(a[i]>e) c2++;
		}
		long long int w=1;
		for(int i=0;i<(k-c2);i++)
		{
			w=w*(count-i);
			w/=i+1;
		}
		cout<<w<<endl;
       	t--;
	}
	return 0;
}
