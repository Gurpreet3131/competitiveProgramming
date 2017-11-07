#include <bits/stdc++.h>
using namespace std;

struct hero
{
	string name;
	int a;
	int v;
	int s;
};
struct hero obj[100002];

bool comp(const hero& one, const hero& two)
{
	if(one.a == two.a)
	{
		if(one.v == two.v)
		{
			if(one.s == two.s) return one.name < two.name;
			else return one.s < two.s;
		}
		else return one.v > two.v;

	}
	else return one.a > two.a;
}
int main()
{

	int n; scanf("%d", &n);	
	for(int i = 0; i < n; i++)
	{
		cin >> obj[i].name;
		cin >> obj[i].a >> obj[i].v >> obj[i].s;
	}
	sort(obj, obj+n, comp);
	for(int i = 0; i < n; i++)
	{
		cout << obj[i].name << endl;
	}
	return 0;
}