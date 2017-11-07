#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;
#define INT_MIN -2147483647
#define INT_MAX 2147483647
 
int rmq(int segTree[],int i,int j,int x,int y,int index)
{
    if(i>y||j<x)
        return INT_MIN;
 
    if(x<=i&&j<=y)
        return segTree[index];
 
    return max(rmq(segTree,i,(i+j)/2,x,y,2*index+1),rmq(segTree,(i+j)/2+1,j,x,y,2*index+2));
}
 
void _build(int segTree[],int arr[],int i,int j,int index)
{
    if(i==j)
    {
        segTree[index]=arr[i];
        return;
    }
 
    _build(segTree,arr,i,(i+j)/2,2*index+1);
    _build(segTree,arr,1+(i+j)/2,j,2*index+2);
 
    segTree[index]=max(segTree[2*index+1],segTree[2*index+2]);
}
 
int* buildTree(int arr[],int n)
{
    int* segTree=new int[4*n];
 
    _build(segTree,arr,0,n-1,0);
 
    return segTree;
}
int main()
{
	int twop[15]={0},index[100002]={0};
	twop[0]=0;
	for(int i=1;i<15;i++) twop[i]=pow(2,i)-1;
	int n;
	int a[100002]={0};
	long long int maxsum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		for(int i=1;i<15;i++)
		{
			
		}
	} 
	int *segTree = buildTree(a, n);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if( ( (a[i]&a[j]) == a[j] ) || ( (a[i]&a[j]) == a[i]))
			{
				//cout<<i<<" "<<j<<endl;
				long long int max=rmq(segTree,0,n-1,i,j,0);
				maxsum+=max;
			}
		}
	}
	printf("%lld\n",maxsum);
	return 0;
}