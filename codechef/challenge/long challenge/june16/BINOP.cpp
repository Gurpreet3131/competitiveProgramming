#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	char a[1000002],b[1000002];
	while(t>0)
	{
		int oo=0,zo=0,oz=0,zz=0,opcount=0;
		scanf("%s%s",a,b);
		int length=strlen(a);
		for(int i=0;i<length;i++)
		{
			if(a[i]=='1' && b[i]=='1') oo++;
			else if(a[i]=='1' && b[i]=='0') oz++;
			else if(a[i]=='0' && b[i]=='1') zo++;
			else zz++;
		}
		//cout<<zz<<" "<<zo<<" "<<oz<<" "<<oo<<endl;
		int mini=min(oz,zo);
		opcount=mini;
		oz-=mini; zo-=mini;
		oo+=mini; zz+=mini;
		//cout<<opcount<<endl;
		if(oz==0 && zo==0)
		{
			printf("Lucky Chef\n%d\n",opcount);
		}
		else if(oz==0 && zo!=0)
		{
			if(oo==0) printf("Unlucky Chef\n");
			else
			{
				opcount+=zo;
				printf("Lucky Chef\n%d\n",opcount);
			}
		}
		else if(zo==0 && oz!=0)
		{
			if(zz==0) printf("Unlucky Chef\n");
			else
			{
				opcount+=oz;
				printf("Lucky Chef\n%d\n",opcount);
			}
		}
		t--;
	}
	return 0;
}