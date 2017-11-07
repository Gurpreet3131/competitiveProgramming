#include <iostream>
#include <cstdio>
#define inf 1000000009
using namespace std;
int n,l,maxelement=0,minl;
long long int seg_tree[400001]={0},lazy[400001]={0};
long long int maxsum=0,nn=100000;

void lazy_update(int s,int e,int node_num)
{
  seg_tree[node_num] += lazy[node_num];
  if(e>s)
  {
    lazy[node_num*2] += lazy[node_num]; 
    lazy[node_num*2+1] += lazy[node_num];    
  }
  lazy[node_num] = 0;
}

void set_lazy(int s,int e,long long int new_val,int node_num)
{
   if(e>s)
   {
     int m = (s+e)/2; 
     lazy[node_num*2] += new_val; 
     lazy[node_num*2+1] += new_val;
   }
}

void range_update(int l,int r,long long int new_val,int s,int e,int node_num)
{
  if(lazy[node_num]!=0)
    lazy_update(s,e,node_num);
  if(s>r || e<l)
    return;
  else if(s>=l && e<= r)
    seg_tree[node_num] += new_val , set_lazy(s,e,new_val,node_num);
  else
  {
    int m = (s+e)/2;
    range_update(l,r,new_val,s,m,node_num*2);
    range_update(l,r,new_val,m+1,e,node_num*2+1);
    seg_tree[node_num] = max(seg_tree[node_num*2],seg_tree[node_num*2+1]);
  }
}
int query(int l,int r,int s,int e,int node_num)
{
 if(lazy[node_num]!=0)
    lazy_update(s,e,node_num);
 if(s>r || e<l) 
   return 0;
 else if(s>=l && e<=r) 
   return seg_tree[node_num];
 else 
 {
   int m = (s+e)/2;
   return max(query(l,r,s,m,node_num*2),query(l,r,m+1,e,node_num*2+1));
 }
}
int maxr=0;
struct beauty
{
    int x;
    int y;
    long long int val;

} mat[100002],temp[100001];
void copy(struct beauty arr[], struct beauty temp[], int low, int up )
{
    int i;
    for(i=low;i<=up;i++)
        arr[i]=temp[i];
}
void merge(struct beauty arr[], struct beauty temp[], int low1, int up1, int low2, int up2 )
{
    int i = low1;
    int j = low2 ;
    int k = low1 ;

    while( (i <= up1) && (j <=up2) )
    {
        if(arr[i].x <= arr[j].x)
            temp[k++] = arr[i++] ;
        else
            temp[k++] = arr[j++] ;
    }
    while( i <= up1 )
        temp[k++]=arr[i++];
    while( j <= up2 )
        temp[k++]=arr[j++];
}
void merge_sort( struct beauty arr[], int low, int up )
{
    int i, mid;
    if( low < up )/* if more than one element*/
    {
        mid = (low+up)/2;
        merge_sort( arr, low , mid );  /* Sort arr[low:mid] */
        merge_sort( arr, mid+1, up );  /* Sort arr[mid+1:up] */
        merge( arr, temp, low, mid, mid+1, up ); 
        copy(arr,temp,low, up); 
    }
    
}/*End of merge_sort*/
long long int lsum(int l)
{
    int start=1,end=1,del=1;
    long long int maxs=0;
    while(start<=maxr)
    {
        int limit=start+l-1;
        while(mat[end].x<=limit && end<=n)
        {
            int x=mat[end].x,y=mat[end].y;
            long long int val=mat[end].val;
            int upper,lower;
            upper=max(1,y-l+1);
            lower=y;
            range_update(upper,lower,val,1,nn,1); 
            end++;
        }
        long long int sum=seg_tree[1];
        if(sum>maxs) maxs=sum;
        start++;
        while(mat[del].x<start && del<=n)
        {
            int x=mat[del].x,y=mat[del].y;
            long long int val=mat[del].val;
            int upper,lower;
            upper=max(1,y-l+1);
            lower=y;
            range_update(upper,lower,-val,1,nn,1);
            del++;  
        }
    }
    return maxs;
}
int main()
{
    scanf("%d%d",&n,&l); minl=l;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d%lld",&mat[i].x,&mat[i].y,&mat[i].val);
        if(mat[i].val>maxelement) maxelement=mat[i].val; 
        if(mat[i].x>maxr) maxr=mat[i].x;
        if(mat[i].y>maxr) maxr=mat[i].y;
    }
    merge_sort(mat,1,n);
    maxsum=lsum(l);
    long long int templ=l,maxls=-1;
    if(maxsum==maxelement) minl=1;
    else
    {
        int s=1,e=l;
        while(true)
        {
            if(s>=e) break; 
            l=(s+e)/2;
            if(l<=1 || l>=templ) break;
            maxls=-1;
            for(int i=0;i<400001;i++) seg_tree[i]=0,lazy[i]=0;
            maxls=lsum(l);
            if(maxls==maxsum) 
            {
                minl=l; e=l;
            }
            else if(maxls<maxsum) s=l+1;
            else if(maxls>maxsum) e=l;
        }
    }
    printf("%lld %d\n",maxsum,minl);
    return 0;
}