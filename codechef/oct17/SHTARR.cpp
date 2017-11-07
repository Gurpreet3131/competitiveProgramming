#include <bits/stdc++.h>
using namespace std;
const int size = 1100003;
int a[size];
int nextmax[size], far[size], ct[size], cummax[size];
int ans[size];
int bucketsize, buckets, n;
void setnextmax(int buckets, int n)
{
	int sbucket = n / bucketsize;
	if(n % bucketsize == 0) sbucket--;

	for(int k = 0; k <= sbucket; k++)
	{
		stack<int> s;
		int ind = k * bucketsize + 1;
		if(ind > n) continue;
		s.push(ind);
		cummax[ind] = a[ind];
		for(int i = 2; i <= bucketsize; i++)
		{
			ind = k * bucketsize + i;
			if(ind > n) break;
			cummax[ind] = max(cummax[ind - 1], a[ind]);
			int next = ind, ival;
			while(!s.empty())
			{
				ival = s.top(); s.pop();
				if(a[ind] > a[ival]) nextmax[ival] = next;
				else
				{
					s.push(ival); break;
				}
			}
			s.push(ind);
		}
		while(!s.empty()) 
		{
			int ival = s.top(); s.pop();
			nextmax[ival] = -1;
		}
	}
}

void setfarthest(int start, int n)
{
	int sbucket = start / bucketsize;
	if(start % bucketsize == 0) sbucket--;

	for(int k = sbucket; k >= 0; k--)
	{
		for(int i = bucketsize; i >= 1; i--)
		{
			int ind = k * bucketsize + i;
			if(ind > n) continue;
			far[ind] = -1; ct[ind] = 0;
			if(i == bucketsize || ind == n) continue;
			else
			{
				int nextind = nextmax[ind];
				if(nextind > 0) // its present in the block
				{
					far[ind] = nextind; ct[ind] = 1;
					if(far[nextind] > 0)
					{
						far[ind] = far[nextind];
						ct[ind] = ct[nextind] + 1;
					}
				}
				else
				{
					far[ind] = -1; ct[ind] = 0;
				}
			}
		}
	}
}

void updatefarthest(int start, int n)
{
	int sbucket = start / bucketsize;
	if(start % bucketsize == 0) sbucket--;
	int maxi = (sbucket + 1) * bucketsize;
	for(int i = start; i > sbucket * bucketsize; i--)
	{
		far[i] = -1; ct[i] = 0;
		if(i == maxi) continue;
		else
		{
			int nextind = nextmax[i];
			if(nextind > 0) //it is in the same bucket
			{
				far[i] = nextind; ct[i] = 1;
				if(far[nextind] > 0)
				{
					far[i] = far[nextind];
					ct[i] = ct[nextind] + 1;
				}
			}
			else
			{
				far[i] = -1; ct[i] = 0;
			}
		}
	}
}
void updatesetmax(int start, int n)
{
	int sbucket = start / bucketsize;
	if(start % bucketsize == 0) sbucket--;	
	stack<int> s;
	int ind = sbucket * bucketsize + 1;
	s.push(ind);
	cummax[ind] = a[ind];
	for(int i = 2; i <= bucketsize; i++)
	{
		ind = sbucket * bucketsize + i;
		if(ind > n) break;
		cummax[ind] = max(cummax[ind - 1], a[ind]);
		int next = ind, ival;
		while(!s.empty())
		{
			ival = s.top(); s.pop();
			if(a[ind] > a[ival]) nextmax[ival] = next;
			else
			{
				s.push(ival); break;
			}
		}
		s.push(ind);
	}
	while(!s.empty()) 
	{
		int ival = s.top(); s.pop();
		nextmax[ival] = -1;
	}
}
int bival = -1;
void binarySearch(long long int l, long long int r, long long int limit)
{
	//cout << l << " " << r << endl;
	if(l <= r)
	{
		int mid = (l + r) / 2;
	//	cout << cummax[mid] << " " << limit << endl;
		if(cummax[mid] >= limit) bival = mid, r = mid - 1; 
		else l = mid + 1;
		
		binarySearch(l , r, limit);
	}
}

int getnextindex(int start, int limit)
{
	int sbucket = start / bucketsize;
	if(start % bucketsize == 0) sbucket--;
	int last = n / bucketsize;
	if(n % bucketsize == 0) last--;
	sbucket++;
	int indexval = -1; 
	while(sbucket <= last)
	{
		bival = -1;
		int l = sbucket * bucketsize + 1, r = min((sbucket+1) * bucketsize, n);
		binarySearch(l, r, limit);
		indexval = bival;
		if(indexval > 0) break;
		sbucket++;
	}
	return indexval;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int q; scanf("%d%d",&n, &q);
		nextmax[0] = -1; far[0] = -1;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		bucketsize = sqrt(n);
		buckets = n / bucketsize + 1;
		setnextmax(buckets, n);
		setfarthest(n, n);

		while(q--)
		{
			char c; cin >> c; 
			int ival, l, r;
			long long int x;
			if(c == '+')
			{
				scanf("%d%lld", &ival, &x);
				a[ival] += x;
				updatesetmax(ival, n);
				updatefarthest(ival, n);
			}
			else
			{
				scanf("%d%d%d", &ival, &l, &r);
				long long int answer = 0;
				int ind = ival;

				while(ind > 0 && a[ind] < l)
				{
					//cout << "ind = " << ind << endl;
					int farind = far[ind];

					if(farind > 0) //there exist biggest in bucket
					{
						if(a[farind] >= l) break; //and perform linear
						else ind = getnextindex(farind, l); //nextmax[farind];
					}
					else 
					{
						ind = getnextindex(ind, l); //nextmax[ind];
					}
				}
				// come out with a[ind]>=l in a bucket, or -1
				//check for first bucket,  and last bucket sep
				while(ind > 0 && a[ind] < l) ind = nextmax[ind];
				while(ind > 0 && a[ind] < r && a[ind] >= l)
				{
					int farind = far[ind];
					//l = a[ind] + 1;
					if(farind > 0)
					{
						if(a[farind] < r) 
						{
							//count all valid in buck and
							//move to nerxt bucket
							answer += 1 + ct[ind]; 
							ind = getnextindex(farind, a[farind] + 1);  // nextmax[farind];
						}
						else break;
							//break it and perform linear
					}
					else
					{
						answer += 1 + ct[ind];
						ind = getnextindex(ind, a[ind] + 1); // nextmax[ind];
					}
				}
				while(ind > 0 && a[ind] < r && a[ind] >= l)
				{
					//cout << "ind = " << ind << endl;
					answer++; 
					ind = nextmax[ind];
				}
				if(ind > 0) answer++;
				printf("%lld\n",answer);
			}
			
		}
	}
	return 0;
}