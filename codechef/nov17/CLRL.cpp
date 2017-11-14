#include <bits/stdc++.h>
using namespace std;
const int size = 1000001;
int a[size];
int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, rat; scanf("%d%d",&n,&rat);
		int l = 0, r = 1e9 + 1, flag = 1;
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i = 0; i < n; i++)
		{
			if(i == 0)
			{
				if(a[i] > rat) r = a[i];
				else if(a[i] < rat) l = a[i];
			}
			else
			{
				if(a[i] > rat) //go to left
				{
					if(a[i] > r)
					{
						flag = 0; break;
					}
					else r = a[i];
				}
				else if(a[i] < rat)//go to right 
				{
					if(a[i] < l)
					{
						flag = 0; break;
					}
					else l = a[i];
				}
			}
		}
		if(flag == 1) printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}
