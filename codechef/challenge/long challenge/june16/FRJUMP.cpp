#include<bits/stdc++.h>
#include<string.h>
#define mod 1000000007
using namespace std;
int main()
{
	long long int a[100004]={0};
	int bignum[1000000];
	//int digR[100004]={0};
	int type,p,R;
	long long int f;
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++) { //cout<<i<<endl; 
		scanf("%lld",&a[i]);
	}
	int q; scanf("%d",&q);
	while(q>0)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d%lld",&p,&f);
			a[p-1]=f;
		}
		else
		{
			scanf("%d",&R);
			long long int enjoy=a[0];
			int index=0;
			long long int temp=enjoy,carry=0;
			while(temp>0)
			{
				bignum[index++]=temp%10;
				temp/=10;
			}
			for(int i=1;i*R<n;i++)
			{
				temp=a[i*R];
				carry=0;
				for(int j=0;j<index;j++)
				{				
					long long mul=temp*bignum[j]+carry;
					bignum[j]=mul%10; carry=mul/10;
				}
				while(carry>0)
				{
					bignum[index++]=carry%10; carry/=10;
				}
				//cout<<enjoy<<endl;
				enjoy*=a[i*R];
				//cout<<enjoy<<endl;
				if(enjoy>=mod) enjoy%=mod;
				//if(enjoy==0) break;
			}
			int firstdig=bignum[index-1];
			printf("%d %lld\n",firstdig,enjoy);
		}
		q--;
	}
	return 0;
}