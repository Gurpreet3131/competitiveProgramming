    #include <bits/stdc++.h>
    using namespace std;
    #define LL long long
    #define mod 1009419529
    int last[256];
    #define n 10010
    #define k 110
    int dp1[n+k][k],dp2[n+k][k];
    int main()
    {
    	int T;
    	cin>>T;
    	while(T--)
    	{
    		int N,K;
    		string str;
    		cin>>N>>K;
    		cin>>str;
    		str = "A" + str; 
    		memset(dp1,0,sizeof(dp1));
    		memset(dp2,0,sizeof(dp2));
    		memset(last,-1,sizeof(last));
    		dp1[0][0] = 1;
    		dp2[0][0] = 1;
    		LL Ans = 0;
    		for(int i = 1;i<=N+K;i++)
    		{
    			for(int j = 0;j<=K&&j<=i;j++)
    			{
    				dp1[i][j] = dp2[i-1][j];
    				if(last[str[i]]>=i-j)
    				{
    					dp1[i][j]-=dp2[last[str[i]] - 1][j - (i - last[str[i]])];
    					while(dp1[i][j]<0)
    						dp1[i][j]+=mod;
    				}
    				dp2[i][j] = dp1[i][j];
    				if(j>0)
    				{
    					dp2[i][j]+=dp2[i-1][j-1];
    					while(dp2[i][j]>=mod)
    						dp2[i][j]-=mod;
    				}
    			}
    			last[str[i]] = i;
    		}
    		for(int i = N;i<=N+K;i++)
    		{
    			Ans+=dp1[i][i-N];
    			while(Ans>=mod)
    				Ans-=mod;
    		}
    		Ans-=1;
    		if(Ans<0)
    			Ans+=mod;
    		cout<<Ans<<endl;
    	}
    	return 0;
    } 