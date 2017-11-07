#include<bits/stdc++.h>
#include<string.h>
#include <deque>
#define maxv(a,b) a>b?a:b
#define mod 1000000007
using namespace std;
int arr[1001][1001];
int maxj[1001][1001];
int sumj[1001][1001];
int startsum[1001][1001];
int lr[1001];
int rl[1001];
int startmax[1001][1001];
void bMax(int m, int b,int row)
{
	int k=b;
	int n=m;
    // Create a Double Ended Queue, Qi that will store indexes of array elements
    // The queue will store indexes of useful elements in every window and it will
    // maintain decreasing order of values from front to rear in Qi, i.e., 
    // arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order
    std::deque<int>  Qi(k);
 
    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < k; ++i)
    {
        // For very element, the previous smaller elements are useless so
        // remove them from Qi
        while ( (!Qi.empty()) && maxj[row][i] >= maxj[row][Qi.back()])
            Qi.pop_back();  // Remove from rear
 
        // Add new element at rear of queue
        Qi.push_back(i);
    }
 	int index=0;
    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for ( ; i < n; ++i)
    {
        // The element at the front of the queue is the largest element of
        // previous window, so print it
        startmax[row][index++]=maxj[row][Qi.front()];
 		//cout<<maxj[row][Qi.front()]<<endl;
        // Remove the elements which are out of this window
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();  // Remove from front of queue
 
        // Remove all elements smaller than the currently
        // being added element (remove useless elements)
        while ( (!Qi.empty()) && maxj[row][i] >= maxj[row][Qi.back()])
            Qi.pop_back();
 
         // Add current element at the rear of Qi
        Qi.push_back(i);
    }
 
    // Print the maximum element of last window
    startmax[row][index++]=maxj[row][Qi.front()];
    //cout<<maxj[row][Qi.front()]<<endl;
}
void aMax(int n, int a,int col)
{
	int k=a;
    // Create a Double Ended Queue, Qi that will store indexes of array elements
    // The queue will store indexes of useful elements in every window and it will
    // maintain decreasing order of values from front to rear in Qi, i.e., 
    // arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order
    std::deque<int>  Qi(k);
 
    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < k; ++i)
    {
        // For very element, the previous smaller elements are useless so
        // remove them from Qi
        while ( (!Qi.empty()) && arr[i][col] >= arr[Qi.back()][col])
            Qi.pop_back();  // Remove from rear
 
        // Add new element at rear of queue
        Qi.push_back(i);
    }
 	int index=0;
    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for ( ; i < n; ++i)
    {
        // The element at the front of the queue is the largest element of
        // previous window, so print it
        maxj[index++][col]=arr[Qi.front()][col];
 		//cout<<maxj[row][Qi.front()]<<endl;
        // Remove the elements which are out of this window
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();  // Remove from front of queue
 
        // Remove all elements smaller than the currently
        // being added element (remove useless elements)
        while ( (!Qi.empty()) && arr[i][col] >= arr[Qi.back()][col])
            Qi.pop_back();
 
         // Add current element at the rear of Qi
        Qi.push_back(i);
    }
 
    // Print the maximum element of last window
    maxj[index++][col]=arr[Qi.front()][col];
}
int main()
{
	long long int allsum=0;
	int n,m; scanf("%d%d",&n,&m);
	int maxele=0,posi=0,posj=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
			allsum+=arr[i][j];
			if(arr[i][j]>maxele) 
			{
				maxele=arr[i][j];
				posi=i; posj=j;
			}
		}
	}
	int q; scanf("%d",&q);
	while(q>0)
	{
		int a,b; scanf("%d%d",&a,&b);
		int mintime=mod;
		if(a==1 && b==1) mintime=0;
		else if(a==n && b==m)
		{
			mintime=(a*b*maxele)-allsum;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					startsum[i][j]=0;
					startmax[i][j]=0;
					maxj[i][j]=0;
				}
			}
			long long int sum=0,tempmintime=0,tempmax=0;

			for(int j=0;j<m;j++)
			{
				aMax(n,a,j);
			}
			for(int i=0;i<n-a+1;i++)
			{
				bMax(m,b,i);
			}
			for(int j=0;j<m;j++)
			{
				sum=0;
				for(int i=0;i<a;i++) 
				{
					sum+=arr[i][j];
				}
				sumj[0][j]=sum;
				for(int i=1;i<n-a+1;i++)
				{
					sum+=arr[i+a-1][j]-arr[i-1][j];
					sumj[i][j]=sum;
				}
			}
			for(int i=0;i<n-a+1;i++)
			{
				sum=0;
				for(int j=0;j<b;j++)
				{
					sum+=sumj[i][j];
				}
				startsum[i][0]=sum;
				for(int j=1;j<m-b+1;j++)
				{
					sum+=sumj[i][j+b-1]-sumj[i][j-1];
					startsum[i][j]=sum;
				}
			}
			for(int i=0;i<n-a+1;i++)
			{
				for(int j=0;j<(m-b+1);j++)
				{
					tempmintime=a*b*startmax[i][j]-startsum[i][j];
					if(tempmintime<mintime) mintime=tempmintime;
					if(mintime==0) break;
				}
				if(mintime==0) break;
			}			
			memset(lr,0,sizeof(lr));
			memset(rl,0,sizeof(rl));
		} 
		printf("%d\n",mintime);
		q--;
	}
	return 0;
}