#include<bits/stdc++.h>
using namespace std;
int priority(char ch)
{
	switch(ch)
	{
		case '(': return 0;
		case '+': return 1;
		case '-': return 2;
		case '*': return 3;
		case '/': return 4;
		case '^': return 5;
	}
}
int main()
{
	int t; scanf("%d",&t);
	char infix[401]={},postfix[401]={},stack[401]={};
	while(t>0)
	{
		scanf("%s",infix);

		int index=0,stackindex=0,length=strlen(infix);
		for(int i=0;i<length;i++)
		{
			char ch=infix[i];
			//cout<<ch<<endl;
			
			if(ch=='(') stack[stackindex++]=ch;
			else if(ch>96 && ch<123)
			{
				postfix[index++]=ch;
			}
			else if(ch==')')
			{
				ch=stack[--stackindex];
				while(ch!='(')
				{
					postfix[index++]=ch;
					stack[stackindex]=' ';
					ch=stack[--stackindex];
				}
				stack[stackindex]=' ';
			}
			else
			{
				int prch=priority(ch),pr=priority(stack[stackindex-1]);
				//cout<<prch<<" "<<pr<<endl;
				if(prch>pr)
				{
					stack[stackindex++]=ch;
				}
				else
				{
					while(priority(ch)<=priority(stack[stackindex-1]) && stackindex>0)
					{
						postfix[index++]=stack[--stackindex];
					}
					stackindex++;
					stack[stackindex++]=ch;
				}
			}
			//cout<<"postfix: "<<postfix<<endl;
			//cout<<"stack: "<<stack<<endl;
		}
		while(stackindex!=-1)
		{
			postfix[index++]=stack[--stackindex];
		}
		printf("%s\n",postfix);
		t--;
	}
	return 0;
}