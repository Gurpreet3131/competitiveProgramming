#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	long long int a[100004];
	scanf("%d",&n);	
	long long int mx=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int flag=1;
	if(n<=2)
	{
		printf("YES\n"); return 0;
	}
	int q[10],rear=0;
	for(int i=0;i<=3;i++) q[i]=-1;
	for(int i=0;i<n;i++)
	{
		int f=0;
		for(int j=0;j<=2;j++)
		{
			if(a[i]==q[j])
			{
				f=1; break;
			}
		}
		//cout<<f<<endl;
		if(f==0) q[rear++]=a[i];
		//for(int i=0;i<rear;i++) cout<<q[i]<<" ";
		//	cout<<endl;
		if(rear>3)
		{
			flag=0; break;
		}
	}
//	for(int i=0;i<rear;i++) cout<<q[i]<<" ";
//			cout<<endl;
		
//	cout<<flag<<endl;
	if(flag==1)
	{
		if(rear==3)
		{
			sort(q,q+rear);
			if(q[1]-q[0] != q[2]-q[1])
			{
				flag=0;
			}
		}
	}
	if(flag==1) printf("YES\n");
	else printf("NO\n");
	return 0;
}