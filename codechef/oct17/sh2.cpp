    #include <bits/stdc++.h>
    using namespace std;
    const int size = 1100003;
    long long int a[size];
    long long int nextmax[size], far[size], ct[size];
    long long int ans[size], blockmax[size];
    int blockind[size]; 
    int bucketsize, buckets;
    void setnextmax(int start, int n)
    {
    	//3 7 2 4 8 7
    	stack<long long int> s;
    	s.push(1);
     
    	for(int i = 2; i <= start; i++)
    	{
    		int next = i, ind;
    		while(!s.empty())
    		{
    			ind = s.top(); s.pop();
    			if(a[next] > a[ind]) nextmax[ind] = next;
    			else 
    			{
    				s.push(ind); break;
    			}
    		}
    		s.push(i);
    	}
    	while(!s.empty()) 
    	{
    		int ind = s.top(); s.pop();
    		nextmax[ind] = -1;
    	}
    }
     
    void setfarthest(int start, int n)
    {
    	
    	int sbucket = start / bucketsize;
    	if(start % bucketsize == 0) sbucket--;
     
    	for(int k = sbucket; k >= 0; k--)
    	{
    		blockmax[k] = -1; blockind[k] = -1;
    		for(int i = bucketsize; i >= 1; i--)
    		{
    			int ind = k * bucketsize + i;
    			far[ind] = -1; ct[ind] = 0;
    			if(a[ind] >= blockmax[k])
    			{
    				blockmax[k] = a[ind];
    				blockind[k] = ind;
    			}
     
    			if(i == bucketsize) continue;
    			else
    			{
    				int nextind = nextmax[ind];
    				if(nextind > 0)
    				{
    					if(nextind <= ((k+1) * bucketsize))
    					{
    						far[ind] = nextind; ct[ind] = 1;
    						if(far[nextind] > 0)
    						{
    							far[ind] = far[nextind];
    							ct[ind] = ct[nextind] + 1;
    						}
    					}
    					else // it lies on next bucket or does not exist
    					{
    						far[ind] = -1; ct[ind] = 0;
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
    	int maxi = (sbucket+1) * bucketsize; 
    	if(a[start] >= blockmax[sbucket])
    	{
    		if(a[start] == blockmax[sbucket]) 
    			blockind[sbucket] = min(blockind[sbucket], start);
    		else
    		{
    			blockmax[sbucket] = a[start];
    			blockind[sbucket] = start;
    		}
    	}
    	for(int i = start; i > sbucket * bucketsize; i--)
    	{
    		//int ind = k * bucketsize + i;
    		far[i] = -1; ct[i] = 0;
    		if(i == maxi) continue;
    		else
    		{
    			int nextind = nextmax[i];
    			if(nextind > 0)
    			{
    				if(nextind <= maxi)
    				{
    					far[i] = nextind; ct[i] = 1;
    					if(far[nextind] > 0)
    					{
    						far[i] = far[nextind];
    						ct[i] = ct[nextind] + 1;
    					}
    				}
    				else // it lies on next bucket or does not exist
    				{
    					far[i] = -1; ct[i] = 0;
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
    	//int maxi = (sbucket+1) * bucketsize - 1; 
    	int ival = start;
     
    	/*if(ival == n) nextmax[ival] = -1;
    	else
    	{
    		if(a[ival+1] > a[ival]) nextmax[ival] = ival+1;
    		else
    		{
    			int ind = ival+1;
    			while(ind > 0)
    			{
    				if(a[ind] > a[ival])
    				{
    					nextmax[ival] = ind; break;
    				}
    				else ind = nextmax[ind];
    			}
    		}
    	}*/
    	for(int i = start; i > sbucket * bucketsize; i--)
    	{
    		nextmax[i] = -1;
    		if(i == n) nextmax[i] = -1;
    		else
    		{
    			if(a[i+1] > a[i]) nextmax[i] = i+1;
    			else
    			{
    				int ind = i+1;
    				while(ind > 0)
    				{
    					if(a[ind] > a[i])
    					{
    						nextmax[i] = ind; break;
    					}
    					else ind = nextmax[ind];
    				}
    			}
    		}
    	}
    	sbucket--;
    	while(sbucket >= 0)
    	{
    		start = (sbucket + 1) * bucketsize;
    		for(int i = start; i >= blockind[sbucket]; i--)
    		{
    			nextmax[i] = -1;
    			if(i == n) nextmax[i] = -1;
    			else
    			{	
    				if(a[i+1] > a[i]) nextmax[i] = i+1;
    				else
    				{
    					int ind = i+1;
    					while(ind > 0)
    					{
    						if(a[ind] > a[i])
    						{
    							nextmax[i] = ind; break;
    						}
    						else ind = nextmax[ind];
    					}
    				}
    			}
    		}
    		sbucket--;
    	}
    }
    int main()
    {
    	int t; scanf("%d",&t);
    	while(t--)
    	{
    		int n, q; scanf("%d%d",&n, &q);
    		nextmax[0] = -1; far[0] = -1;
    		for(int i = 1; i <= n; i++)
    		{
    			scanf("%lld", &a[i]);
    		}
    		bucketsize = sqrt(n);
    		buckets = n / bucketsize + 1;
    		setnextmax(n, n);
    		
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
     
    				int nextind = nextmax[ival];
    				updatesetmax(ival, n);
    				
    				//setnextmax(ival, n);
    				updatefarthest(ival, n);
    				//setfarthest(ival, n);
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
    						if(a[farind] >= l) break;
    						else ind = nextmax[farind];
    					}
    					else ind = nextmax[ind];
    				}
    				// come out with a[ind]>l in a bucket, or -1
    				//check for first bucket,  and last bucket sep
    				while(ind > 0 && a[ind] < l) ind = nextmax[ind];
    				while(ind > 0 && a[ind] < r && a[ind] >= l)
    				{
    					//cout << "ind = " << ind << endl;
    					int farind = far[ind];
    					if(farind > 0)
    					{
    						if(a[farind] < r) 
    						{
    							//count all valid in buck and
    							//move to nerxt bucket
    							answer += 1 + ct[ind]; 
    							ind = nextmax[farind];
    						}
    						else break;
    							//break it and perform linear
    					}
    					else
    					{
    						answer += 1 + ct[ind];
    						ind = nextmax[ind];
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