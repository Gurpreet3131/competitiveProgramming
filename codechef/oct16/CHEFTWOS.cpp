#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int l,sub=0;
int isgood(char a[],int cur, int visited[], int viscount)
{
	visited[cur] = 1; viscount++;
	if(cur == l-1)
	{
		if(viscount == l) return 1;
		else return 0;
	}
	int lt=0,rt=0;
	if(a[cur]=='1') 
	{
		if(cur-1>=0) 
			if(visited[cur-1]==0) 
				lt=isgood(a,cur-1,visited,viscount);
		
		if(cur+1<l)
			if(visited[cur+1] == 0)
				rt = isgood(a,cur+1,visited,viscount);
	}
	else if(a[cur]=='2')
	{
		if(cur-2>=0) 
			if(visited[cur-2]==0) 
				lt=isgood(a,cur-2,visited,viscount);
		
		if(cur+2<l)
			if(visited[cur+2] == 0)
				rt = isgood(a,cur+2,visited,viscount);
	}
	visited[cur] = 0;
	viscount++;
	if(lt == 1 || rt == 1) return 1;
	else return 0;
}
void allpos(char a[],char b[],int cur)
{
	int visiteda[l+1]={0};
	int visitedb[l+1]={0};
	if(cur == l) return;

	if(a[cur] != b[cur])
	{
		int f = isgood(a,0,visiteda,0);
		int f2 = isgood(b,0,visitedb,0);	
		allpos(a,b,cur+1);

		for(int i=0;i<l;i++) visiteda[i]=0,visitedb[i]=0;

		swap(a[cur],b[cur]);
		f = isgood(a,0,visiteda,0);
		f2 = isgood(b,0,visitedb,0);
		if(f ==1 && f2 == 1)
		{
			sub++;
			//cout<<a<<" "<<b<<endl;
		} 
		allpos(a,b,cur+1);
	}
	else allpos(a,b,cur+1);
}
int main()
{
	int t; scanf("%d",&t);
	long long int two[100005]={0};
	two[0]=1;
	for(int i=1;i<100001;i++)
	{
		two[i] = 2*two[i-1];
		if(two[i]>=mod) two[i]%=mod;
	}	int lt=0,rt=0;

	char a[100005],b[100005];
	while(t--)
	{
		scanf("%s%s",a,b);
		sub=0;
		l= strlen(a);
		int same=0;
		for(int i=0;i<l;i++)
		{
			if(a[i] == b[i]) same++;
		}
		int visiteda[l+1]={0}, viscount=0;
		int gooda = isgood(a,0,visiteda,viscount);
		viscount=0;
		int visitedb[l+1]={0};
		int goodb = isgood(b,0,visitedb,viscount);
		//cout<< gooda<<" "<<goodb<<endl;
		if(gooda ==1 && goodb==1) sub=1;
		if(same==l)
		{
			if(gooda ==1 && goodb==1) sub = two[same];
		}
		else
		{
			allpos(a,b,0);
			
			sub*=two[same];
		}
		if(sub>=mod) sub%=mod;
		printf("%d\n",sub);
	}
	return 0;
}