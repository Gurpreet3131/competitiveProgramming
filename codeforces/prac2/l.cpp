#include <bits/stdc++.h>
using namespace std;
int b[1001]={0},r[1001]={0},bind=0,rind=0;
int findval(string seg)
{
	int num=0;
	for(int i=0;i<seg.length()-1;i++)
	{
		num= num*10+(seg[i]-'0');
	}
	return num;
}
int main()
{	
	int s; scanf("%d",&s);
	for(int i=0;i<s;i++)
	{
		string seg;
		cin>>seg;
		int length= seg.length();
		int num = findval(seg);
		if(seg[length-1]=='B')	b[bind++]=num;
		else r[rind++]=num;
	}	
	sort(b,b+bind); sort(r,r+rind);
	bind--; rind--;
	long long int maxlen=0,ct=0;
	while(bind>=0 && rind>=0)
	{
		maxlen+=b[bind--]; maxlen+=r[rind--];
		ct+=2;
	}
	maxlen-=ct;
	cout<<maxlen<<endl;
	return 0;
}
