#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
	set<int> s;
	int q; scanf("%d",&q);
	set<int>::iterator itr;		
	while(q-->0)
	{
		int type,x;
		scanf("%d%d",&type,&x);
		if(type==1) s.insert(x);
		else if(type==2) s.erase(x);
		else 
		{
			itr=s.find(x);
			if(itr==s.end()) printf("No\n");
			else printf("Yes\n");
		}
	}
	return 0;
}