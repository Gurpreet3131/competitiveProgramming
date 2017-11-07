#include <bits/stdc++.h>
using namespace std;
map<long long int, int> present;
map<long long int, int> mval;
int main()
{
	int t; scanf("%d", &t);
	while(t--)
	{
		int n, q; scanf("%d%d",&n, &q);
		long long int ival[q+1], jval[q+1], vval[q+1];
		long long int ind, ind2;
		present.clear(); mval.clear();

		for(int i = 0; i < q; i++)
		{
			scanf("%lld%lld%lld",&ival[i], &jval[i], &vval[i]);
			ind = ival[i] * n + jval[i];
			present[ind] = 1; mval[ind] = vval[i]; 
		}
		for(int i = 0; i < q; i++)
		{
			ind = ival[i] * n + jval[i];
			ind2 = jval[i] * n + ival[i];
			if(present[ind2] == 0)
			{
				present[ind2] = 1;
				mval[ind2] = mval[ind];
			}
		}
int
		 flag = 1;
		for(int i = 0; i < q; i++)
		{
			ind = ival[i] * n + jval[i];
			ind2 = jval[i] * n + ival[i];
			//if(present[ind] == 1 && present[ind2] == 1)
			{
				if(ind == ind2)
				{
					if(mval[ind] != 0)
					{
						flag == 0; break;
					}
				}
				else
				{
					if(mval[ind] != mval[ind2])
					{
						flag = 0; break;
					}
				}
			}
			if(flag == 1)
			{
				if(ival[i] < jval[i]) swap(ival[i], jval[i]);
				ind = ival[i] * n + jval[i];
				ind2 = jval[i] * n + ival[i];
				
				long long int ind3, ind4, ind5, ind6;
				for(int k = ival[i] - 1; k>0; k--)
				{
					ind3 = k * n + ival[i];
					ind4 = k * n + jval[i];
					ind5 = ival[i] * n + k;
					ind6 = jval[i] * n + k;
					if(present[ind3] == 1 && present[ind4] == 1)
					{
						// 0 0  1 1   0 1, 1 0
  						//   0    0          1
						if(mval[ind3] == mval[ind4])
						{
							if(mval[ind] == 1) 
							{
								flag = 0; break;
							}
						}
						else
						{
							if(mval[ind] == 0)
							{
								flag = 0; break;
							}
						}					
					}
					else if(present[ind3] == 1)
					{
						if(mval[ind3] == mval[ind])
						{
							mval[ind4] = 0; mval[ind6] = 0;
						}
						else 
						{
							mval[ind4] = 1; mval[ind6] = 1;
						}
					}
					else if(present[ind4] == 1)
					{
						// 0 0  1 1   0 1, 1 0
  						//   0    0          1
						if(mval[ind4] == mval[ind])
						{
							mval[ind3] = 0; mval[ind5] = 0;
						}
						else 
						{
							mval[ind3] = 1; mval[ind5] = 1;
						}
					}
				}
				if(flag == 0) break;
			}
		}
		if(flag == 1) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}