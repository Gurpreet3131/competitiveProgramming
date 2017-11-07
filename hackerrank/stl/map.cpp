#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
using namespace std;
int main()
{
	string name;
	map<string,int> m;
	int q; scanf("%d",&q);
	map<string,int>::iterator itr;		
	while(q-->0)
	{
		int type,x;
		cin>>type;
		cin>>name;
		if(type==1)
		{
			cin>>x;
			itr=m.find(name);
			if(itr==m.end())
			{
				m.insert(make_pair(name,x));
			}
			else
			{
				int temp=m[name];
				m.erase(name);
				m.insert(make_pair(name,temp+x));
			}
			//cout<<m[name]<<endl;
		}
		else if(type==2) m.erase(name);
		else 
		{
			itr=m.find(name);
			if(itr==m.end())
			{
				printf("0\n");
			}
			else printf("%d\n",m[name]);
		}
	}
	return 0;
}