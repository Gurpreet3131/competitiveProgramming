#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int queue[1000000]={0},front=0,rear=0;
int visited[20002]={0};
int main()
{
	int n,m;
	long long int steps=0;
	scanf("%d%d",&n,&m);
	if(n>=m) steps=n-m;
	else
	{
		visited[n]=1;
		queue[0]=n;
		while(front<=rear)
		{
			int pop = queue[front++];
			if(pop-1>0 && visited[pop-1]==0)
			{
				queue[++rear]=pop-1;
				visited[pop-1]=visited[pop]+1;
				if(pop-1 == m) {steps=visited[pop-1]-1; break; }
			} 
			if(pop*2<20001)
			{
				if(visited[pop*2]==0)
				{
					queue[++rear]=pop*2;
					visited[pop*2]=visited[pop]+1;
					if(pop*2 == m) {steps=visited[pop*2]-1; break;} 
				}
			}
		}
	}
	printf("%lld\n",steps);
	return 0;
}