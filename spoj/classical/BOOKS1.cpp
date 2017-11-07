#include <bits/stdc++.h>
using namespace std;
long long int page[502], minmax = 1e9;
int m, k;

int findct(int val)
{
	int ct = 1;
	long long int sum = 0;
	for(int i = 0; i < m; i++)
	{
		if(page[i] > val) return k + 1;
		sum += page[i];
		if(sum > val)
		{
			ct++; sum = page[i];
		}
	}
	return ct;
}

void binarySearch(int l, int r)
{
	if(l <= r)
	{
		int mid = (l + r) / 2;
		//cout << " mid = " << mid << endl;
		int ct = findct(mid);
		if(ct <= k) 
		{
			if(mid < minmax) minmax = mid;
			r = mid - 1;
		}
		else l = mid + 1;
		binarySearch(l, r);
	}
}

void print()
{
	long long int sum = 0;
	stack<int> ind; int left = k - 1;
	for(int i = m - 1; i >=0; i--)
	{
		if(i + 1 == left)
		{
			ind.push(i); left--;
			continue;
		}
		sum += page[i];
		if(sum > minmax) 
		{
			sum = page[i];
			//cout << sum << endl;
			ind.push(i); left--;
		}

	}
	//cout << minmax << endl;
	int cur = -1;
	if(!ind.empty())
	{
		cur = ind.top(); ind.pop();
	}
	for(int i = 0; i < m; i++)
	{
		printf("%lld ", page[i]);
		if(cur == i)
		{
			printf("/ ");
			if(!ind.empty())
			{
				cur = ind.top(); ind.pop();
			}
		}
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		cin >> m >> k;
		for(int i = 0; i < m; i++)
		{
			scanf("%lld", &page[i]);
		}
		int l = 1, r = INT_MAX;
		minmax = r;
		binarySearch(l, r);
		print();
		printf("\n");
	}
	return 0;
}