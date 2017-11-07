#include <bits/stdc++.h>
using namespace std;
long long int seg2[400001]={0},seg5[400001]={0},lazy2[400001]={0},lazy5[400001]={0};
long long int a[100001]={0},a2[100001],a5[100001];
long long int two[100002]={0},five[100001]={0};
long long int sum2[100002]={0},sum5[100001]={0};
int lazyl[400001]={0},lazyr[400001]={0},lazy2y[400001]={0},lazy5y[400001]={0};
void buildsegtree(int s,int e,int nodenum)
{
	if(s == e)
	{
		seg2[nodenum] = a2[s];
		seg5[nodenum] = a5[s];
		lazy2[nodenum] = 0;
		lazy5[nodenum] = 0;
		lazy2y[nodenum] = 0;
		lazy5y[nodenum] = 0;
		lazyl[nodenum] = 0; lazyr[nodenum] = 0;
		return;
	}
	int mid = (s+e)/2;
	buildsegtree(s,mid,nodenum*2);
	buildsegtree(mid+1,e,nodenum*2+1);
	seg2[nodenum] = seg2[nodenum*2]+seg2[nodenum*2+1];
	seg5[nodenum] = seg5[nodenum*2]+seg5[nodenum*2+1];
	lazy5[nodenum] = 0;
	lazy2[nodenum] = 0;
	lazy2y[nodenum] = 0;
	lazy5y[nodenum] = 0;
	lazyl[nodenum] = 0; lazyr[nodenum] = 0;
}
void lazy_update(int s,int e,int nodenum)
{
	if(lazyl[nodenum]>0)
	{
		seg2[nodenum] = (sum2[lazyr[nodenum]]-sum2[lazyl[nodenum]-1])+lazy2y[nodenum]*(e-s+1);
		seg5[nodenum] = (sum5[lazyr[nodenum]]-sum5[lazyl[nodenum]-1])+lazy5y[nodenum]*(e-s+1);
		if(lazy2[nodenum]>0 || lazy5[nodenum]>0)
		{
			seg2[nodenum] += (e-s+1)*lazy2[nodenum];
			seg5[nodenum] += (e-s+1)*lazy5[nodenum];
		}

		if(e>s)
		{
			int m = (s+e)/2;
			lazy2y[nodenum*2] = lazy2y[nodenum]; 
   			lazy2y[nodenum*2+1] = lazy2y[nodenum];
   			
   			lazy5y[nodenum*2] = lazy5y[nodenum]; 
   			lazy5y[nodenum*2+1] = lazy5y[nodenum];

   			lazy2[nodenum*2] = lazy2[nodenum]; 
   			lazy2[nodenum*2+1] = lazy2[nodenum];
   			
   			lazy5[nodenum*2] = lazy5[nodenum]; 
   			lazy5[nodenum*2+1] = lazy5[nodenum];


			lazyl[nodenum*2] = lazyl[nodenum]; lazyr[nodenum*2]= lazyl[nodenum]+(m-s);
			lazyl[nodenum*2+1] = lazyr[nodenum*2]+1; lazyr[nodenum*2+1] = lazyr[nodenum];
		}
		lazy2[nodenum]=0;
		lazy5[nodenum]=0;
		lazy2y[nodenum]=0;
		lazy5y[nodenum]=0;
		lazyl[nodenum] = 0; lazyr[nodenum]=0;
	}
	else
	{
		seg2[nodenum] += ((e-s+1)*lazy2[nodenum]);
 		seg5[nodenum] += ((e-s+1)*lazy5[nodenum]);
 	 	if(e>s)
  		{
    		lazy2[nodenum*2] += lazy2[nodenum]; 
   			lazy2[nodenum*2+1] += lazy2[nodenum];
   			lazy5[nodenum*2] += lazy5[nodenum]; 
   			lazy5[nodenum*2+1] += lazy5[nodenum];    
  		}
  		lazy2[nodenum] = 0;
  		lazy5[nodenum] = 0;
	}
  	
}
 
void set_lazy(int s,int e,long long int c2,long long int c5, int nodenum)
{

   	if(e>s)
   	{
     	lazy2[nodenum*2] += c2; 
     	lazy2[nodenum*2+1] += c2;
     	lazy5[nodenum*2] += c5; 
     	lazy5[nodenum*2+1] += c5;
   	}
}
void set_lazyy(int s,int e,long long int c2,long long int c5,int numl,int numr,int nodenum)
{
	if(e>s)
   	{
    	int m = (s+e)/2; 
     	lazy2y[nodenum*2] = c2; 
     	lazy2y[nodenum*2+1] = c2;

     	lazy2[nodenum*2] = 0; 
     	lazy2[nodenum*2+1] = 0;
     	//
     	lazyl[nodenum*2] = numl; 
     	lazyr[nodenum*2] = numl+ (m-s);

     	lazyl[nodenum*2+1] = lazyr[nodenum*2]+1;
     	lazyr[nodenum*2+1] = numr; 
     	//
     	lazy5y[nodenum*2] = c5; 
     	lazy5y[nodenum*2+1] = c5;

     	lazy5[nodenum*2] = 0; 
     	lazy5[nodenum*2+1] = 0;
     	

     	//lazyl[nodenum*2] = lazyl[nodenum]; lazyr[nodenum*2]= lazyl[nodenum]+(m-s);
		//lazyl[nodenum*2+1] = lazyl[nodenum]+ (e-(m+1)); lazyr[nodenum*2+1] = lazyr[nodenum];
		
   	}
}
void range_update(int l,int r,long long int c2,long long int c5,int s,int e,int nodenum)
{
  	if(lazy2[nodenum]>0 || lazy5[nodenum]>0 || lazyl[nodenum]>0)
    	lazy_update(s,e,nodenum);

  	if(s>r || e<l)
    	return;
  	else if(s>=l && e<= r)
    {
    	seg2[nodenum] += ((e-s+1)*c2);
    	seg5[nodenum] += ((e-s+1)*c5); 
    	set_lazy(s,e,c2,c5,nodenum);
    }
  	else
 	{
    	int m = (s+e)/2;
    	range_update(l,r,c2,c5,s,m,nodenum*2);
    	range_update(l,r,c2,c5,m+1,e,nodenum*2+1);
    	seg2[nodenum] = seg2[nodenum*2]+seg2[nodenum*2+1];
		seg5[nodenum] = seg5[nodenum*2]+seg5[nodenum*2+1];
  	}
}
void range_updatey(int l,int r,long long int c2,long long int c5,int s,int e,int nodenum)
{
  	if(lazy2[nodenum]>0 || lazy5[nodenum]>0 || lazyl[nodenum]>0)
    	lazy_update(s,e,nodenum);

  	if(s>r || e<l)
    	return;
  	else if(s>=l && e<=r)
  	{
  		seg2[nodenum] = c2*(e-s+1)+(sum2[e-l+1] - sum2[s-l]);
  	
  		seg5[nodenum] = c5*(e-s+1)+(sum5[e-l+1] - sum5[s-l]);
  		cout<<"check = "<<seg2[nodenum]<<" "<<seg5[nodenum]<<endl;
  		set_lazyy(s,e,c2,c5,s-l+1,e-l+1,nodenum);
  		
  	}
  	/*else if(s==e && s>=l && s<=r)
  	{
    	int temp = s-l+1;
    	seg2[nodenum] = c2+two[temp];
    	seg5[nodenum] = c5+five[temp]; 
    }*/
  	else
 	{
    	int m = (s+e)/2;
    	range_updatey(l,r,c2,c5,s,m,nodenum*2);
    	range_updatey(l,r,c2,c5,m+1,e,nodenum*2+1);
    	seg2[nodenum] = seg2[nodenum*2]+seg2[nodenum*2+1];
		seg5[nodenum] = seg5[nodenum*2]+seg5[nodenum*2+1];
  	}
}
int query2(int l,int r,int s,int e,int node_num)
{
 	if(lazy2[node_num]>0 || lazyl[node_num]>0)
    	lazy_update(s,e,node_num);
 	if(s>r || e<l) 
   		return 0;
 	else if(s>=l && e<=r) 
   		return seg2[node_num]; 
 	else 
 	{
   		int m = (s+e)/2;
   		return query2(l,r,s,m,node_num*2)+query2(l,r,m+1,e,node_num*2+1);
 	}
}
int query5(int l,int r,int s,int e,int node_num)
{
 	if(lazy5[node_num]>0 || lazyl[node_num]>0)
    	lazy_update(s,e,node_num);
 	if(s>r || e<l) 
   		return 0;
 	else if(s>=l && e<=r) 
   		return seg5[node_num]; 
 	else 
 	{
   		int m = (s+e)/2;
   		return query5(l,r,s,m,node_num*2)+query5(l,r,m+1,e,node_num*2+1);
 	}
}

int main()
{
	int t; scanf("%d",&t);
	
	for(int i=1;i<100001;i++)
	{
		long long int temp=i;
		while(temp%2==0)
		{
			temp/=2; two[i]++;
		}
		while(temp%5==0)
		{
			temp/=5; five[i]++;
		}
		sum2[i]+=two[i];
		sum5[i]+=five[i];
	}
	while(t--)
	{
		int n,m;
		long long int ans2=0,ans5=0,ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) 
		{
			a2[i]=0; a5[i]=0;
			scanf("%lld",&a[i]);
			long long int temp = a[i];
			while(temp%2==0)
			{
				temp/=2; a2[i]++;
			}
			while(temp%5==0)
			{
				temp/=5; a5[i]++;
			}
			cout<<i<<" "<<a2[i]<<" "<<a5[i]<<endl;
		}
		buildsegtree(1,n,1);
		for(int i=1;i<=m;i++)
		{
			int type,l,r;
			scanf("%d%d%d",&type,&l,&r);
			if(type == 1)
			{
				long long int x; scanf("%lld",&x);
				long long int c2=0,c5=0;
				long long int temp = x;
				while(temp%2==0)
				{
					temp/=2; c2++;
				}
				while(temp%5==0)
				{
					temp/=5; c5++;
				}
				range_update(l,r,c2,c5,1,n,1);
				cout<<"x= "<<c2<<" "<<c5<<endl;
			}
			else if(type == 2) 
			{
				long long int y; scanf("%lld",&y);
				long long int c2=0,c5=0;
				long long int temp = y;
				while(temp%2==0)
				{
					temp/=2; c2++;
				}
				while(temp%5==0)
				{
					temp/=5; c5++;
				}
				range_updatey(l,r,c2,c5,1,n,1);
				cout<<"y= "<<c2<<" "<<c5<<endl;
			}
			else
			{
				
				ans2= query2(l,r,1,n,1);
				ans5= query5(l,r,1,n,1);
				ans+= min(ans2,ans5);
				cout<<"ans= "<<ans<<endl;
			}
			cout<<"tree=\n ";
			for(int i=1;i<=10;i++)
			{
				cout<<i<<": "<<seg2[i]<<" "<<seg5[i]<<endl;
			}
			cout<<"tree end\n";
		}
		printf("%lld\n",ans);
	}
	return 0;
}