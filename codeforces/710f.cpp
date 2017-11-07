#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <cmath>
using namespace std;
int main()
{
	int t; 
	scanf("%d",&t);
	map<string,int>m;
	map<string,int> :: iterator itr;
	while(t-->0)
	{
		int type; 
		string s; 
		scanf("%d",&type); cin>>s;
		if(type==1)
		{
			itr=m.find(s);
			if(itr==m.end()) //nt found
			{
				m[s]=1;
			}
			else m[s]+=1;
		}
		else if(type==2)
		{
			itr=m.find(s);
			if(m[s]==1) m.erase(s);
			else m[s]--;
		}
		else
		{
			itr=m.find(s);
			printf("%d\n",m[s]);
		}
	}
	return 0;
}