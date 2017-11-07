#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> m;
long long int n = 1000001;
long long int p[1000001]={0}, prime[100000];
int pindex = 0;
long long int ff[10000] = {0};

void segmentedSieve(long long int a, long long int b)
{
    // Compute all primes smaller than or equal
    // to square root of n using simple sieve
    //long long int limit = floor(sqrt(n))+1;
    //long long int n = b;
    long long int limit = b-a+1;
    //vector<int> prime;  
    //simpleSieve(limit, prime); 
 
    // Divide the range [0..n-1] in different segments
    // We have chosen segment size as sqrt(n).
    long long int low  = a;
    long long int high = b;
 
    // While all segments of range [0..n-1] are not processed,
    // process one segment at a time
    //while (low < n)
    {
        // To mark primes in current range. A value in mark[i]
        // will finally be false if 'i-low' is Not a prime,
        // else true.
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        // Use the found primes by simpleSieve() to find
        // primes in current range
        for (int i = 0; i < pindex; i++)
        {
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i] (divisible by prime[i])
            // For example, if low is 31 and prime[i] is 3,
            // we start with 33.
            long long int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
 
            /*  Mark multiples of prime[i] in [low..high]:
                We are marking j - low for j, i.e. each number
                in range [low, high] is mapped to [0, high-low]
                so if range is [50, 100]  marking 50 corresponds
                to marking 0, marking 51 corresponds to 1 and
                so on. In this way we need to allocate space only
                for range  */
            for (long long int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
 
        // Numbers which are not marked as false are prime
        for (long long int i = low; i<high; i++)
            if (mark[i - low] == true)
                {
                	m[i] = 1;
                }
 
        // Update low and high for next segment
    }
}
/*
long long int rec(long long int temp)
{
	long long int max = 0, deg=0;
	if(m[temp] == 0 && temp > 1)
	{
		for(long long int j=1;j<=sqrt(temp); j++)
		{
			if(temp%j == 0)
			{
				deg += 1;
				long long int score = rec(j);
				if(score > max) max = score;
				long long int k = temp/j;
				if(j != k && k<temp)
				{
					deg += 1;
					score = rec(k); 
					if(score > max) max = score;
				} 
			}
		}
		m[temp] = max + deg + 1;
		//cout<<temp<<" show "<<m[temp]<<endl;
		return m[temp];
	}
	else return m[temp];
}*/

long long int val(long long int temp)
{
	int ind = 0, tt;
	long long int sum = 0;
	int flag = 0, find = 0;
	if(temp == 1) return 1;
	while(temp!=1)
	{
		if(m[temp] == 1)
		{
			flag = 1; break;
		}
		else if(temp<n)
		{
			tt = temp;
			if(p[tt] == 0)
			{
				flag = 1; break;
			}
		}
		else if(prime[ind] > sqrt(temp))
		{
			flag = 1; break;
		}
		//cout<<temp<<endl;
		if(temp%prime[ind] == 0)
		{
			long long int ct = 0;
//			if(fac == 0) fac = temp/prime[ind];
			
			while(temp%prime[ind] ==0) 
			{
				temp/=prime[ind];
				ct++;
				//cout<<"temp= "<<temp<<endl;
				//return 0;
			}			
			ff[find++] = ct;
		}
		ind++;
		if(ind>= pindex)
		{
			flag = 1; break;
		}
	}
	if(flag == 1)
	{
		ff[find++] = 1;
	}
	//for(int i=0;i<find;i++)
	{
	//	cout<<ff[i]<<endl;
	}
	while(1)
	{
		sort(ff,ff+find);
		//for(int i=0;i<find;i++) cout<<ff[i]<<" ";
		//-	cout<<endl;
		long long int pr = 1;
		int flag = 1;
		for(int i=0;i<find;i++)
		{
			if(i<find-1 || find == 1) pr*= (ff[i]+1);
			if(ff[i] != 1) flag = 0;
		}
		if(find > 1)
		{
			long long int b = ff[find-2]+1;
			long long int a = ff[find-1]+1;
			if(a != b) pr*= ( (a*(a+ 1)) - (b*(b+1)) )/2;
			else pr*= a;
			if(a!=b) ff[find-1] = b;
		}
		//cout<<"pr= "<<pr<<endl;
		sum+= pr; ff[find-1]--;
		if(flag == 1)
		{
			//find--;
			sum+= pow(2,find) -2;
			break;
		}
	}
		//sum+=pr;
	//cout<<"sum = "<<sum<<endl;
	return sum;
}
int main()
{
	for(int i = 2; i<n; i++)
	{
		if(p[i] == 0)
		{
			prime[pindex++] = i;
			m[i] = 1;
			for(int j = i*2;j<n;j+=i)
			{
				p[j]++;
			}
		}
	}
	long long int a,b, sum = 0;
	cin>>a>>b;
	if(b>=n) segmentedSieve(a,b);

	for(long long int i=a;i<=b;i++)
	{
		if(i == 1) continue;
		long long int temp = val(i);
		//cout<<temp<<endl;
		sum += temp;
	}
	printf("%lld\n",sum);
	return 0;
}