#include <bits/stdc++.h>
using namespace std;
long long int x[750001],y[750001];

int main()
{
	int n;
	scanf("%d",&n);
	long long int maxdist=0; 
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&x[i],&y[i]);
		for(int j=0;j<i;j++)
		{
			long long int temp;
			temp = ( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
			//cout<<x[i]<<" "<<x[j]<<" "<<temp<<endl;
			if(temp>maxdist)
			{
				maxdist = temp;
			}
		}
		printf("%lld\n",maxdist);
	}
}