#include <bits/stdc++.h>
using namespace std;
const int size = 2001;
int maxm, xlen, ylen;
string x, y;
int issubseq(int mid)
{
	int flag = 0;
	if(mid == 0) return 1;
	else
	{
		int cur = 0, ct = 0; 
		for(int i = 0; i < ylen && cur < xlen; i++)
		{
			if(x[cur] == y[i])
			{
				ct++; 
				if(ct == mid) cur++, ct = 0;
			}
			if(cur == xlen)
			{
				flag = 1; break;
			}
		}
	}
	return flag;
}
void binarySearch(int l, int r)
{
	if(l <= r)
	{
		int mid = (l + r) >> 1;
		int flag = issubseq(mid);
		if(flag == 1)
		{
			maxm = max(maxm, mid);
			l = mid + 1;
		}
		else r = mid - 1;
		binarySearch(l, r);
	}
}

int main()
{
	int t; scanf("%d", &t);
	while(t--)
	{
		cin >> x >> y;
		xlen = x.length(); ylen = y.length();
		int m = ylen / xlen;
		int l = 0, r = m;
		maxm = 0;
		binarySearch(l, r);
		printf("%d\n", maxm);
	}
	return 0;
}