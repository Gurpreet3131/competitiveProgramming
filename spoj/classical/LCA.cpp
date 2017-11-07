    #include <string>
    #include <vector>
    #include <algorithm>
    #include <numeric>
    #include <set>
    #include <map>
    #include <queue>
    #include <iostream>
    #include <sstream>
     
    #include <cassert>
    #include <limits>
    #define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
    #define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
    #define each(it,o) for(auto it= (o).begin(); it != (o).end(); ++ it)
    #define all(o) (o).begin(), (o).end()
    #define mp(x,y) make_pair((x),(y))
    #define mset(m,v) memset(m,v,sizeof(m))
    #define INF 0x3f3f3f3f
    #define INFL 0x3f3f3f3f3f3f3f3fLL
    #define inrep int t;cin>>t; while(t--)
    using namespace std;
     
    typedef vector<int> vi;
    typedef pair<int,int> pii;
    typedef vector<pii > vpii;
    typedef long long ll;
    typedef vector<ll> vll;
    typedef pair<ll,ll> pll;
    typedef vector<pll > vpll;
    typedef vector<string> vs;
    typedef long double ld;
     
    template<typename T> ostream& operator<< ( ostream &o,vector<T> v ) {
        if ( v.size() >0 )
            o<<v[0];
        for ( unsigned   i=1; i<v.size(); i++ )
            o<<" "<<v[i];
        return o<<endl;
    }
    template<typename U,typename V> ostream& operator<< ( ostream &o,pair<U,V> p ) {
        return o<<"("<<p.first<<", "<<p.second<<") ";
    }
    template<typename T> istream& operator>> ( istream &in,vector<T> &v ) {
     
        for ( unsigned   i=0; i<v.size(); i++ )
            in>>v[i];
        return in;
    }
     
    template <typename U> struct RMQ {
        U cmp;
        const int n;
        const int maxl;
        const vi &A;
     
     
        vector<vi> maxv;
        RMQ ( const vi&_A ) :n ( _A.size() ),maxl ( 32-__builtin_clz ( n ) ),A ( _A ),maxv ( maxl,vi ( n ) ) {
            build();
     
        }
        void build() {
            rep ( i,n )
            maxv[0][i]=i;
            for ( int j=1; 1<<j <=n ; j++ ) {
                for ( int i=0,k=1<< ( j-1 ); k<n; i++,k++ ) {
                    if ( cmp ( A[maxv[j-1][i]],A[maxv[j-1][k]] ) )
                        maxv[j][i]=maxv[j-1][i];
                    else
                        maxv[j][i]=maxv[j-1][k];
                }
            }
        }
        int query ( int s,int e ) {
            int k=31-__builtin_clz ( e-s ); // k = log(e-s)
            if ( cmp ( A[maxv[k][s]],A[maxv[k][e- ( 1<<k ) ]] ) )
                return maxv[k][s];
            return maxv[k][e- ( 1<<k ) ];
        }
    };
     
     
    typedef RMQ<less<int>> RMinQ;
    typedef RMQ<greater<int>> RMaxQ;
    struct DFSTour {
        const int n;
        const vector<vi> &adj;
        vi tour;
        vi first;
        vi depth;
        DFSTour ( const vector<vi> & _adj, int root=0 ) : n ( _adj.size() ),adj ( _adj ),first ( n ),depth ( n ) {
            build ( root );
        }
        int _cnt=0;
        void build ( int r ) {
            _cnt=0;
            tour.clear();
            _build ( r,-1,0 );
        }
        void _build ( int r, int p,int d ) {
            depth[r]=d;
            tour.push_back ( r );
            first[r]=_cnt++;
            for ( int j: adj[r] ) if ( j!=p ) {
                    _build ( j,r,d+1 );
                    tour.push_back ( r );
                    _cnt++;
                }
        }
    };
     
    struct LCA {
        const int n;
        DFSTour dfs;
     
        vi d;
        RMinQ rmq;
        vi buildDepth() {
            vi t ( dfs.tour.size() );
            rep ( i,dfs.tour.size() ) {
                t[i]=dfs.depth[dfs.tour[i]];
            }
            return t;
        }
        LCA ( const vector<vi> _adj,int root=0 ) : n ( _adj.size() ),dfs ( _adj,root ),d ( buildDepth() ),rmq ( d ) {
        }
     
        int query ( int a, int b ) {
            if ( dfs.first[a]>dfs.first[b] ) swap ( a,b );
            int ind=rmq.query ( dfs.first[a],dfs.first[b]+1 );
            return dfs.tour[ind];
        }
    };
    #define gc getchar_unlocked
     
    void scan ( int &x ) {
        int c = gc();
        x = 0;
        for ( ; ( c<48 || c>57 ); c = gc() );
        for ( ; c>47 && c<58; c = gc() ) {
            x = ( x << 1 ) + ( x << 3 ) + c - 48;
        }
    }
    int main() {
    //     ios_base::sync_with_stdio ( false );
        int n;
    //     cin>>n;
        scan ( n );
        vector<vi> adj ( n );
        rep ( i,n-1 ) {
            int x,y;
    //         cin>>x>>y;
            scan ( x );
            scan ( y );
            x--;
            y--;
            adj[x].push_back ( y );
            adj[y].push_back ( x );
        }
        LCA lca ( adj );
        int q;
    //     cin>>q;
        scan ( q );
        vi &dep=lca.dfs.depth;
        vi res ( q );
    //     string res;
        rep ( i,q ) {
            int r,u,v;
    //         cin>>r>>u>>v;
            scan ( r );
            scan ( u );
            scan ( v );
            r--;
            u--;
            v--;
            if ( dep[u]>dep[v] ) swap ( u,v );
            int l1=lca.query ( r,u );
            int l2=lca.query ( r,v );
            int l3=lca.query ( u,v );
            int l;
            if ( dep[l1]<dep[l3]) l=l3;
            else if ( abs ( dep[l1]-dep[r] ) <abs ( dep[l2]-dep[r] ) ) l=l1;
            else l=l2;
            res[i]=l+1;
    //         res+=to_string(l+1)+'\n';
    //         cout<<l+1<<'\n';
        }
    //     cout<<res;
        for ( int r: res ) printf ( "%d\n",r );
    }
     