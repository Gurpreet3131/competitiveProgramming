#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);	
	long long int a[100004]={0},rear=0;
	map<long long int,int> ind;
	map<long long int,int >::iterator it;
	map<long long int,int> ct;
	while(t-->0)
	{
		char ch;
		long long int ai,ss=0,num=0; 
		cin>>ch;
		char s[20];
		int length=strlen(s);
		if(ch=='+')
		{
			cin>>ai;
			long long int temp=ai;
			int sindex=17;
			while(temp>0)
			{
				int dd=temp%10; temp/=10;
				if(dd%2==0) s[sindex--]='0';
				else s[sindex--]='1';
			}			
			for(int j=sindex;j>=0;j--)
			{
				s[j]='0';
			}

		//	cout<<s<<endl;
			for(int i=0;i<=17;i++)
			{
				num+=((int)(s[i]-'0'))*pow(2,17-i);
			}
		//	cout<<"num= "<<num<<endl;
			
			it=ind.find(num);
			if(it==ind.end())
			{
				a[rear++]=num;
				ind[num]=rear-1;
				ct[num]=1;
			}
			else 
			{
				ct[num]++;
			}
		}
		else if(ch=='-')
		{
			cin>>ai;
			long long int temp=ai;
			int sindex=17;
			while(temp>0)
			{
				int dd=temp%10; temp/=10;
				if(dd%2==0) s[sindex--]='0';
				else s[sindex--]='1';
			}			
			for(int j=sindex;j>=0;j--)
			{
				s[j]='0';
			}
			for(int i=0;i<=17;i++)
			{
				num+=((int)(s[i]-'0'))*pow(2,17-i);
			}
			if(ct[num]==1)
			{
				int indx=ind[num];
				ind.erase(num);
				ct.erase(num);
				a[indx]=a[rear-1];
				ind[a[rear-1]]=indx;
				rear--;
			}
			else
			{
				ct[num]--;
			}
		}
		else if(ch=='?')
		{
			cin>>s;
			int length=strlen(s);
			int cot=0;
			int sindex=length-1;
			for(int j=17;j>=0;j--)
			{
				if(sindex>=0) s[j]=s[sindex--];
				else
				{
					s[j]='0';
				}
			}
			//cout<<s<<endl;
			for(int i=0;i<=17;i++)
			{
				ss+=((int)(s[i]-'0'))*pow(2,17-i);
			}
			//cout<<"ss= "<<ss<<endl;
			it = ct.find(ss);
			if(it != ct.end())
			{
				cot+=ct[ss];
			}				
			printf("%d\n",cot);
		}

	}
	return 0;
}