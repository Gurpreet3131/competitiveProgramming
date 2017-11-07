#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node * left;
    struct node * right;
};
struct node * newnode(int data)
{
    struct node * temp = (node *)malloc(sizeof(node));
    temp -> data = data;
    temp->left = temp -> right = NULL;
    return temp;
}

void insert(struct node * temp, string s, int data)
{
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == 'L') 
		{
			if(temp -> left == NULL) 
				temp->left = newnode(0);
			temp = temp->left;
		}
		else 
		{
			if(temp -> right == NULL)
				temp -> right = newnode(0);
			temp = temp -> right;
		}
		if(i == s.length() - 1) temp -> data = data;
	}
}
int maxans = 0;
int traverse(struct node * temp)
{	
	if(temp == NULL)
	{
		return 0;
	}
	else
	{
		int ldepth = traverse(temp->left);
		int rdepth = traverse(temp->right);
		maxans = max(maxans, ldepth + rdepth + 1);
		if(ldepth > rdepth) return ldepth + 1;
		else return rdepth+1;
	}
}
int main()
{
	int t, x;
	cin >> t >> x;
	struct node * root = newnode(x);
    for(int i = 0; i < t - 1; i++)
    {
    	string s; cin >> s;
    	int data; cin >> data;
    	insert(root, s, data);
    }
    int ans = traverse(root);
    ans = maxans;
    cout << ans << endl;
    return 0;
}
