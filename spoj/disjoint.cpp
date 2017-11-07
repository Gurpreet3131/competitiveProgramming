#include <bits/stdc++.h>
using namespace std;
int root[1001],size[1001];
int n, m;

void init()
{
	for(int i = 0; i < n; i++)
	{
		root[i] = i;
		size[i] = 1;
	}
}

int findroot(int i)
{
	while(root[i] != i)
	{
		root[i] = root[root[i]];
		i = root[i];
	}
	return i;
}

void wunion(int a, int b)
{
	int roota = findroot(a);
	int rootb = findroot(b);
	if(roota == rootb) return;
	if(size[roota] > size[rootb])
	{
		root[rootb] = roota;
		size[roota] += size[rootb]; 
	}
	else 
	{
		root[roota] = rootb;
		size[rootb] += size[roota];
	}
}

bool find(int a, int b)
{
	if(findroot(a) == findroot(b))
		return true;
	else return false;
}

int main()
{
	cin >> n >> m;
	init();
	for(int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		wunion(a - 1, b - 1);
		int ct[1001] = {0};
		vector<int> v;
		for(int j = 0; j < n; j++)
		{
			int r = findroot(j);
			if(ct[r] == 0)
			{
				v.push_back(size[r]);
				ct[r] = 1;
			}
		}
		sort(v.begin(), v.end());
		for(int j = 0; j < v.size(); j++)
		{
			cout << v[j] << " ";
		}
		cout << endl;
	}
    return 0;
}
