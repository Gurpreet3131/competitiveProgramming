/*
Logic - Since every employee has a manager except for one, the 
employee without manager can be treated as root node of the tree.
Since an employee can only have one maganer, therefore, there will
be only one parent of each node except for the root node. Thus, the 
data structure obtained is a tree. 

So, at first tree is generated where the parent node points to the 
child node. The entry with NULL managerId is the root node.

NOTE - Since I have used C++, I am using a negative interger except for NULL

Now, traverse the tree in DFS style starting from root node, this will
generate the XML code with required indentation.

Any negative value can be used in place to NULL to make it work.

Input format -
1 Dinesh 2
2 Ramesh 4
3 Sandeep 4
4 Abhishek -1

instead of - 

1 Dinesh 2
2 Ramesh 4
3 Sandeep 4
4 Abhishek NULL

will run the code
*/
#include <bits/stdc++.h>
using namespace std;
int n = 4, root, tabs = 0;
struct employee
{
	int id;
	string name;
	int managerId;
};
struct employee e[100];
vector<vector<int> > tree;
vector<int> row;

void dfsUtil(int node, int visited[])
{
	visited[node] = 1;
	//printing tabs for indentation
	for(int i = 0; i < tabs; i++)
		cout<<"    ";
	//printing the XML
	cout << "<Node name=\"" << e[node].name << "\" id=\"" 
	<< e[node].id << "\">\n";

	for(int i = 0; i < tree[node].size(); i++)
	{
		int newNode = tree[node][i];
		if(visited[newNode] == 0)
		{
			tabs++;
			dfsUtil(newNode, visited);
		}
	}
	//Printing tabs
	for(int i = 0; i < tabs; i++)
		cout<<"    ";
	//closing tag
	cout << "</Node>\n";
	tabs--;
}

void dfs(int root)
{
	int visited[n+1] = {0};
	dfsUtil(root, visited);
}
int main()
{
	// As per test case
	// n = 4 is default value, to run for other lengths, change value of n

	//taking input, using structure
	for(int i = 1; i <= n; i++)
	{
		cin >> e[i].id >> e[i].name >> e[i].managerId;
		if(e[i].managerId < 0) root = i;
		// for finding the root node 
		// for covention let negative value of managerId denotes NULL
	}
	for(int i = 0; i <=n; i++)
		tree.push_back(row);
	
	//generating tree, as a person can have only one manager
	for(int i = 1; i <=n; i++)
	{
		tree[e[i].managerId].push_back(e[i].id);
	}
	// Uncomment for loop to print tree

	/*for(int i = 1; i <= n; i++)
	{
		int tempid = e[i].id;
		for(int j = 0; j < tree[tempid].size(); j++)
		{
			cout << e[i].id << " -> " << tree[tempid][j] << endl; 
		}
	}*/

	//traverse the tree in dfs pattern and generate XML
	dfs(root);
	return 0;
}