#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	int num;
	while(t--)
	{
		int n,ct[51]={0};
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<6;j++)
			{
				scanf("%d",&num);
				ct[num]++;
			}
		}
		int lot[6]={0},ind=0;
		for(int i=1;i<50;i++)
		{
			if(ct[i]>0)
			{
				int temp = i;
				for(int j=0;j<6;j++)
				{
					if(ct[temp]>ct[lot[j]])
					{
						int tt = lot[j];
						lot[j] = temp;
						temp = tt;
					}
					else if(ct[temp]==ct[lot[j]]) 
					{
						int tt = lot[j];
						if(temp<lot[j])
						{
							lot[j]=temp;
							temp = tt;
						}
					}
				}
			}
			/*cout<<"i= "<<i<<endl;
			for(int i=0;i<6;i++)
			{
				printf("%d ",lot[i]);
			}
			cout<<endl;
			*/
		}
		int flag=0;
		for(int i=0;i<6;i++)
		{
			if(lot[i] == 7) 
			{
				flag=1; break;
			}
		}
		if(flag==0)
		{
			if(ct[lot[5]] == ct[7]) lot[5]=7;			
		}
		sort(lot,lot+6);
		for(int i=0;i<6;i++)
		{
			printf("%d ",lot[i]);
		}
		cout<<endl;
	}
	return 0;
}