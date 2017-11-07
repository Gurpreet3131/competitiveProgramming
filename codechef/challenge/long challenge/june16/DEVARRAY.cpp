#include<bits/stdc++.h>
#include<string.h>
#define big 1000000005
using namespace std;
int main()
{
	int n,q; scanf("%d%d",&n,&q);
	int a[100003],mini=big,maxi=0,qele;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>maxi) maxi=a[i];
		if(a[i]<mini) mini=a[i];
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&qele);
		if(qele>=mini && qele<=maxi) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}