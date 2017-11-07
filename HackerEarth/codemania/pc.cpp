#include <bits/stdc++.h>

using namespace std;
int p[1000005]={0};
int main()
{
	p[0]=1; p[1]=1;
	for(int i=2;i<1000001;i++)
	{
		if(p[i]==0)
		{
			for(int j=2;i*j<1000001;j++)
			{
				p[i*j]=1;
			}
		}
	}
	int t; scanf("%d",&t);
	while(t--)
	{
		int px,py,ini,fin,dir=1; //f-1,r-2,d-3,l-4
		scanf("%d%d",&px,&py);
		scanf("%d%d",&ini,&fin);
		for(int i=ini;i<fin;i++)
		{
			if(p[i]==0) // left
			{
				if(dir==1) dir=4, px--;
				else if(dir==2) dir=1, py++;
				else if(dir==3) dir=2, px++;
				else if(dir==4) dir=3, py--;
			}
			else //right
			{
				if(dir==1) dir=2, px++;
				else if(dir==2) dir=3, py--;
				else if(dir==3) dir=4, px--;
				else if(dir==4) dir=1, py++;
			}
		}
		printf("%d %d\n",px,py);
	}
	return 0;
}