#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
vector<int> indval[100001];
vector<int> full[100001];
vector<int> dfsnum;
int bank[100001] = {0};
long long int inc[100001] = {0}, incct = 1;
int max1 = -1, max2 = -1, ans = -1;
int nn, bign;
int minbankind[2000001], segmax[2000001], segmax2[2000001];
int ansmax[2000001], ansmax2[2000001];
int m1, m2;
priority_queue<int, vector<int>, greater<int> > pq;
void buildsegtree(int s, int e, int node)
{
	if(s == e)
	{
		minbankind[node] = INT_MAX;
		segmax[node] = dfsnum[s];	
		segmax2[node] = -1;
		ansmax[node] = -1;
		ansmax2[node] = -1;
	}
	else
	{
		int mid = (s + e) / 2;
		buildsegtree(s, mid, node*2);
		buildsegtree(mid + 1, e, node * 2 + 1);
		minbankind[node] = INT_MAX;
		if(e - s == 1)
		{
			segmax2[node] = min(segmax[node * 2], segmax[node * 2 + 1]);
		}
		else
		{
			segmax2[node] = max(segmax2[node * 2], segmax2[node * 2 + 1]);
			int val = min(segmax[node * 2], segmax[node*2+1]);
			if(val > segmax2[node] && val != max(segmax[node*2], segmax[node*2+1])) 
				segmax2[node] = val;
		}
		segmax[node] = max(segmax[node * 2], segmax[node * 2 + 1]);
		ansmax2[node] = -1; ansmax[node] = -1;

	}
}

void update(int l, int r, int mm1, int mm2, int s, int e, int node)
{
	if(s>r || e<l) return;
    else if(s>= l && e <= r)
    {
    	minbankind[node] = s;
    	ansmax[node] = mm1;
    	ansmax2[node] = mm2;
    }
    else
    {
        int mid = (s + e) / 2;
        update(l,r, mm1, mm2, s,mid,node*2);
        update(l,r,mm1, mm2, mid+1,e, node*2 + 1);
        minbankind[node] = min(minbankind[node*2],minbankind[node*2 + 1]);
   		if(e - s == 1)
		{
			ansmax2[node] = min(ansmax[node * 2], ansmax[node * 2 + 1]);
		}
		else
		{
			ansmax2[node] = max(ansmax2[node * 2], ansmax2[node * 2 + 1]);
			int val = min(ansmax[node * 2], ansmax[node*2+1]);
			if(val > ansmax2[node] && val != max(ansmax[node*2], ansmax[node*2+1])) 
				ansmax2[node] = val;
		}
		ansmax[node] = max(ansmax[node * 2], ansmax[node * 2 + 1]);
    }
}

int minquery(int l, int r, int s, int e, int node)
{
	if(s > r || e < l) return INT_MAX;
    else if(s >= l && e <= r) return minbankind[node];
    else
    {
        int mid = (s + e) / 2;
        return min(minquery(l,r,s,mid,node*2),minquery(l,r,mid+1,e,node*2+1));
    }
}

int ansquery1(int l, int r, int s, int e, int node)
{
	if(s > r || e < l) return -1;
    else if(s >= l && e <= r) return ansmax[node];
    else
    {
        int mid = (s + e) / 2;
        int ansl = ansquery1(l,r,s,mid,node*2);
        int ansr = ansquery1(l,r,mid+1,e,node*2+1);
        int ans = max(ansl, ansr);
        if(ansl > 0 && inc[ansl] == incct);
        else 
        {
        	//cout << "inserting1= " << ansl << endl;
        	pq.push(ansl); 
        	if(ansl > 0) inc[ansl] = incct; 
        }
        if(pq.size() > 2) pq.pop();
        
        if(ansr > 0 && inc[ansr] == incct);
        else 
        {
        	//if(ansr > 0)cout << inc[ansr] <<  " " << incct << endl;
        	//cout << "inserting2= " << ansr << endl;
        	pq.push(ansr); 
        	if(ansr > 0) inc[ansr] = incct; 
        }
        if(pq.size() > 2) pq.pop();
		
		if(ans > 0 && inc[ans] == incct);
        else 
        {
        	//cout << "inserting3= " << ans << endl;
        	pq.push(ans); 
        	if(ans > 0) inc[ans] = incct; 
        }
        if(pq.size() > 2) pq.pop();
        return ans;
    }
}
int ansquery2(int l, int r, int s, int e, int node)
{
	if(s > r || e < l) return -1;
    else if(s >= l && e <= r) 
    {
    	return ansmax2[node];
    }
    else
    {
        int mid = (s + e) / 2;
        int ansl, ansr, ans;
       	ansl = ansquery2(l,r,s,mid,node*2);
       	ansr = ansquery2(l,r,mid+1,e,node*2+1);
       	ans =  max(ansl, ansr);
       	if(ansl > 0 && inc[ansl] == incct);
        else 
        {
        	//cout << "inserting1= " << ansl << endl;
        	pq.push(ansl); 
        	if(ansl > 0) inc[ansl] = incct; 
        }
        if(pq.size() > 2) pq.pop();
        
        if(ansr > 0 && inc[ansr] == incct);
        else 
        {
        	//if(ansr > 0)cout << inc[ansr] <<  " " << incct << endl;
        	//cout << "inserting2= " << ansr << endl;
        	pq.push(ansr); 
        	if(ansr > 0) inc[ansr] = incct; 
        }
        if(pq.size() > 2) pq.pop();
		
		if(ans > 0 && inc[ans] == incct);
        else 
        {
        	//cout << "inserting3= " << ans << endl;
        	pq.push(ans); 
        	if(ans > 0) inc[ans] = incct; 
        }
        if(pq.size() > 2) pq.pop();
    	return ans;
    }
}
int maxquery1(int l, int r, int s, int e, int node)
{
	if(s > r || e < l) return -1;
    else if(s >= l && e <= r) return segmax[node];
    else
    {
        int mid = (s + e) / 2;
        int ansl = maxquery1(l,r,s,mid,node*2);
        int ansr = maxquery1(l,r,mid+1,e,node*2+1);
        int ans = max(ansl, ansr);
        if(ansl > 0 && inc[ansl] == incct);
        else 
        {
        	//cout << "inserting1= " << ansl << endl;
        	pq.push(ansl); 
        	if(ansl > 0) inc[ansl] = incct; 
        }
        if(pq.size() > 2) pq.pop();
        
        if(ansr > 0 && inc[ansr] == incct);
        else 
        {
        	//if(ansr > 0)cout << inc[ansr] <<  " " << incct << endl;
        	//cout << "inserting2= " << ansr << endl;
        	pq.push(ansr); 
        	if(ansr > 0) inc[ansr] = incct; 
        }
        if(pq.size() > 2) pq.pop();
		
		if(ans > 0 && inc[ans] == incct);
        else 
        {
        	//cout << "inserting3= " << ans << endl;
        	pq.push(ans); 
        	if(ans > 0) inc[ans] = incct; 
        }
        if(pq.size() > 2) pq.pop();
        return ans;
    }
}


int maxquery2(int l, int r, int s, int e, int node)
{
	if(s > r || e < l) return -1;
    else if(s >= l && e <= r) 
    {
    	return segmax2[node];
    }
    else
    {
        int mid = (s + e) / 2;
        int ansl, ansr, ans;
       	ansl = maxquery2(l,r,s,mid,node*2);
       	ansr = maxquery2(l,r,mid+1,e,node*2+1);
       	ans =  max(ansl, ansr);
       	if(ansl > 0 && inc[ansl] == incct);
        else 
        {
        	//cout << "inserting1= " << ansl << endl;
        	pq.push(ansl); 
        	if(ansl > 0) inc[ansl] = incct; 
        }
        if(pq.size() > 2) pq.pop();
        
        if(ansr > 0 && inc[ansr] == incct);
        else 
        {
        	//if(ansr > 0)cout << inc[ansr] <<  " " << incct << endl;
        	//cout << "inserting2= " << ansr << endl;
        	pq.push(ansr); 
        	if(ansr > 0) inc[ansr] = incct; 
        }
        if(pq.size() > 2) pq.pop();
		
		if(ans > 0 && inc[ans] == incct);
        else 
        {
        	//cout << "inserting3= " << ans << endl;
        	pq.push(ans); 
        	if(ans > 0) inc[ans] = incct; 
        }
        if(pq.size() > 2) pq.pop();
    	return ans;
    }
}

void gen(int u, int visited[])
{
	visited[u] = 1;
	dfsnum.push_back(u);
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(visited[v] == 0)
		{
			gen(v, visited);
			dfsnum.push_back(u);
		}
	}
}

void generatedfsnum(int u)
{
	int visited[100001] = {0};
	gen(u, visited);
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n, m; scanf("%d%d",&n,&m);		
		memset(bank, 0, sizeof(bank));
		memset(inc, 0, sizeof(inc));
		dfsnum.clear();
		dfsnum.push_back(0);
		incct = 1;
		for(int i = 1; i <= n; i++)
		{
			adj[i].clear();
			indval[i].clear();
			full[i].clear();
		}
		for(int i = 0; i < n - 1; i++)
		{
			int u, v; scanf("%d%d",&u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		generatedfsnum(1);
		nn = dfsnum.size() - 2;
		for(int i = 1; i <= nn; i++)
		{
			indval[dfsnum[i]].push_back(i);
			full[dfsnum[i]].push_back(i);
		}
		for(int i = 2; i <= nn; i++)
		{
			dfsnum.push_back(dfsnum[i]);
		}
		bign = dfsnum.size() - 1;
		for(int i = nn + 1; i <= bign; i++)
		{
			full[dfsnum[i]].push_back(i);
		}
		for(int i = 1; i <= n; i++)
		{
			indval[i].push_back(indval[i][0]);
		}
		//cout << endl;
		//for(int i = 1; i <= bign; i++)
		{
		//	cout << dfsnum[i] << " ";
		}
		//cout << endl;
		buildsegtree(1,bign,1);

		for(int i = 0; i < m; i++)
		{
			int type,c; scanf("%d%d", &type, &c);
			if(type == 1)
			{
				if(bank[c] == 0)
				{
					bank[c] = 1;
					//for(int j = 0; j < full[c].size();j++)
					{
					//	int lr = full[c][j];
					//	update(lr, lr, 1, bign, 1);
					}	
					for(int j = 0; j < full[c].size(); j++)
					{
						int left = full[c][j];
						//indm1[left] = m1; indm2[left] = m2;
						update(left, left,segmax[left],-1,1,bign,1);
					}
					//for(int i = 1; i <= 31; i++)
					//	cout << i << " " << segmax2[i] << endl;
				}
			}
			else
			{
				max1 = -1; max2 = -1; ans = -1;
				if(bank[c] == 1)
				{
					ans = n - 1;
				}
				else
				{
					int start = indval[c][0], end = nn + indval[c][0];
					int minind = minquery();
					m1 = ansquery1(start, end, 1, bign, 1);							
					m2 = ansquery2(start, end, 1, bign, 1);
							
					if(m1 > max1)
					{
						max2 = max1; max1 = m1;
					}
					else if(m1 > max2) max2 = m1;
					if(m2 > max2) max2 = m2;
					ans = min(max1, max2);
					/*
					m1 = ansquery1(start, end, 1, bign, 1);							
					m2 = ansquery2(start, end, 1, bign, 1);
					incct++;
					while(!pq.empty())
					{
						m2 = pq.top();
						pq.pop(); pq.pop();
					}
					cout << max1 << " " << max2 << endl;
					if(m1 > max1)
					{
						max2 = max1; max1 = m1;
					}
					else if(m1 > max2) max2 = m1;
					if(m2 > max2) max2 = m2;
					/*end--;
					for(int k = 0; k < full[c].size() - 1; k++)
					{
						int subs = full[c][k];
						int subend = full[c][k+1] - 1;
						cout << start << "  " << end << endl;
						cout << subs << " sub " << subend << endl;
						if(subend > end) break;
						m1 = ansquery1(subs, subend, 1, bign, 1);							
						m2 = ansquery2(subs, subend, 1, bign, 1);
						incct++;
						while(!pq.empty())
						{
							m2 = pq.top();
							pq.pop(); pq.pop();
						}
						//m1 = indm1[subs];
						//m2 = indm2[subs];
						cout << m1 << " " << m2 << endl;
						if(m1 > max1)
						{
							max2 = max1; max1 = m1;
						}
						else if(m1 > max2) max2 = m1;
						if(m2 > max2) max2 = m2;
					}
					*/
					//if(i >= 3) return 0;
					//ans = min(max1, max2);
					

					

					/*
					while(start < end)
					{
						//cout << start << " end = " << end << endl;
						int minind = minquery(start, end, 1, bign, 1);
						//cout << "minind = " << minind << endl;

						if(minind >= INT_MAX) break;
						int val = dfsnum[minind];
						//first occurnce of val after start and last occurence vefore end
							
						int subs= minind;
						int subend = subs; // = indval[val][indval[val].size() - 1];
						int l = 0, r = full[val].size() - 1;

						while(l <= r)
						{
							//>= minind <= end  
							int mid = (l + r) / 2;
							int tempind = full[val][mid];
							if(tempind >= minind && tempind <= end)
							{
								subend = max(subend, tempind);
								l = mid + 1;
							}
							else if(tempind < minind) l = mid + 1;
							else if(tempind > end) r = mid - 1;
						}
						//cout << val << " " << subs << " " << subend << endl;
						

						m1 = maxquery1(subs, subend, 1, bign, 1);							
						m2 = maxquery2(subs, subend, 1, bign, 1);
						incct++;
						while(!pq.empty())
						{
							m2 = pq.top();
							pq.pop(); pq.pop();
						}
						//cout << m1 << " " << m2 << endl;
						if(m1 > max1)
						{
							max2 = max1; max1 = m1;
						}
						else if(m1 > max2) max2 = m1;
						if(m2 > max2) max2 = m2;
						start = max(subend + 1, subend + 1000);
						//cout << max1 << " " << max2 << endl;
						//if(i >= 3) return 0;
						ans = min(max1, max2);
						if(ans == n - 1) break;
					}
					*/
				}
				//cout << max1 << " " << max2 << endl;
				printf("%d\n",ans);	
			}
		}
		
	}
}