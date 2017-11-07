#include <bits/stdc++.h>
using namespace std;
const int num = 400001;
long long int a[num]={0},lazy[num]={0};
long long int times[num] = {0}, tlazy[num] = {0};
long long int mod = 1000000007;
int n, m;
void lazy_update1(long long int s, long long int e,int node_num)
{
    a[node_num] += (e - s + 1) * lazy[node_num];
    if(a[node_num] >= mod) a[node_num] %= mod;
    if(e>s)
    {
        lazy[node_num*2] += lazy[node_num]; 
        lazy[node_num*2+1] += lazy[node_num];   
        if(lazy[node_num*2] >= mod) lazy[node_num*2] %= mod;
        if(lazy[node_num*2 + 1] >= mod) lazy[node_num*2+1] %= mod; 
    }
    lazy[node_num] = 0;
}

void set_lazy1(long long int s, long long int e,long long int new_val,int node_num)
{
    if(e>s)
    {
        int m = (s+e)/2; 
        lazy[node_num*2] += new_val; 
        lazy[node_num*2+1] += new_val;
        if(lazy[node_num*2] >= mod) lazy[node_num*2] %= mod;
        if(lazy[node_num*2+1] >= mod) lazy[node_num*2+1] %= mod; 
    }
}

void range_update1(int l,int r,long long int new_val,long long int s, long long int e,int node_num)
{
    if(lazy[node_num] > 0)
        lazy_update1(s,e,node_num);
    if(s>r || e<l)
        return;
    else if(s>=l && e<= r)
    {
        a[node_num] += (e - s + 1) * new_val;
        if(a[node_num] >= mod) a[node_num] %= mod;
        set_lazy1(s,e,new_val,node_num);
    }
    else
    {
        int m = (s+e)/2;
        range_update1(l,r,new_val,s,m,node_num*2);
        range_update1(l,r,new_val,m+1,e,node_num*2+1);
        a[node_num] = a[node_num*2] + a[node_num*2+1];
        if(a[node_num] >= mod) a[node_num] %= mod;
    }
}

int query1(int l,int r, long long int s, long long int e,int node_num)
{
    if(lazy[node_num] > 0)
        lazy_update1(s,e,node_num);
    if(s>r || e<l) 
        return 0;
    else if(s>=l && e<=r) 
        return a[node_num];
    else 
    {
        int m = (s+e)/2;
        return query1(l,r,s,m,node_num*2) + query1(l,r,m+1,e,node_num*2+1);
    }
}

void lazy_update2(long long int s, long long int e,int node_num)
{
    times[node_num] += (e - s + 1) * tlazy[node_num];
    if(times[node_num] >= mod) times[node_num] %= mod;
    if(e>s)
    {
        tlazy[node_num*2] += tlazy[node_num]; 
        tlazy[node_num*2+1] += tlazy[node_num];  
        if(tlazy[node_num*2] >= mod) tlazy[node_num*2] %= mod;
        if(tlazy[node_num*2 + 1] >= mod) tlazy[node_num*2+1] %= mod; 
     
    }
    tlazy[node_num] = 0;
}

void set_lazy2(long long int s, long long int e,long long int new_val,int node_num)
{
    if(e>s)
    {
        int m = (s+e)/2; 
        tlazy[node_num*2] += new_val; 
        tlazy[node_num*2+1] += new_val;
        if(tlazy[node_num*2] >= mod) tlazy[node_num*2] %= mod;
        if(tlazy[node_num*2 + 1] >= mod) tlazy[node_num*2+1] %= mod; 
   
    }
}

void range_update2(int l,int r,long long int new_val, long long int s, long long int e,int node_num)
{
    if(tlazy[node_num] > 0)
        lazy_update2(s,e,node_num);
    if(s>r || e<l)
        return;
    else if(s>=l && e<= r)
    {
        times[node_num] += (e - s + 1) * new_val;
        if(times[node_num] >= mod) times[node_num] %= mod;
        set_lazy2(s,e,new_val,node_num);
    }
    else
    {
        int m = (s+e)/2;
        range_update2(l,r,new_val,s,m,node_num*2);
        range_update2(l,r,new_val,m+1,e,node_num*2+1);
        times[node_num] = times[node_num*2] + times[node_num*2+1];
        if(times[node_num] >= mod) times[node_num] %= mod;
    }
}

int query2(int l,int r, long long int s, long long int e,int node_num)
{
    if(tlazy[node_num] > 0)
        lazy_update2(s,e,node_num);
    if(s>r || e<l) 
        return 0;
    else if(s>=l && e<=r) 
        return times[node_num];
    else 
    {
        int m = (s+e)/2;
        return query2(l,r,s,m,node_num*2) + query2(l,r,m+1,e,node_num*2+1);
    }
}
void print()
{
    cout<<"\na\n";
            for(int i = 1; i <= 2 * n; i++)            
                cout << i << " " << a[i] << endl;;
            cout<<"\nlazy\n";
            for(int i = 1; i <= 2 * n; i++)            
                cout << i << " " << lazy[i] << endl;
            cout <<"\ntimes\n";
            for(int i = 1; i <= 2 * m; i++)            
                cout << i << " " << times[i] << endl;
            cout<<"\ntlazy\n";
            for(int i = 1; i <= 2 * m; i++)            
                cout << i << " " << tlazy[i] << endl;
}
int main()
{
    int t; scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= max(4*n, 4*m); i++)
        {
            a[i] = 0; lazy[i];
            times[i] = 0; tlazy[i] = 0;
        }
        int type[m+2], l[m+2], r[m+2];   
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &type[i], &l[i], &r[i]);
            if(type[i] == 1) range_update1(l[i], r[i], 1, 1, n, 1);
            else range_update2(l[i], r[i], 1, 1, m, 1);
//            print();
        }
        for(int i = m; i >= 1; i--)
        {
            if(type[i] == 2)
            {
                long long int val = query2(i, i, 1, m, 1);
                if(val > 0) range_update2(l[i], r[i], val, 1, m, 1);
//                print();
            }
        }
        for(int i = 1; i <=m; i++)
        {
            if(type[i] == 1)
            {
                long long int val = query2(i, i, 1, m, 1);
                if(val > 0) range_update1(l[i], r[i], val, 1, n, 1);
//                print();
            }
        }
        for(int i = 1; i <= n; i++)
        {
            long long int val = query1(i, i, 1, n, 1);
            printf("%lld ", val);
        }
        printf("\n");
    }
    return 0;
}

