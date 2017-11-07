#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct tree
{
	int vertex;
	struct tree *left;
	struct tree *right;
};
//struct tree stack[100];
//int top=-1;
void preorder(struct tree *root)
{
	if(root==NULL) return;
	printf("%d ",root->vertex);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct tree *root)
{
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->vertex);
}
void inorder(struct tree *root)
{
	if(root==NULL) return;
	inorder(root->left);
	printf("%d ",root->vertex);
	inorder(root->right);
}
/*void push(struct tree *node)
{
	stack[top++]=node;
}
/*struct tree* pop()
{
	if(top==0) 
	{
		cout<<"Stack is empty\n";
		return NULL;
	}
	return stack[--top];
}
/*void preorder(struct tree *root)
{
	if(root==NULL)
	{
		cout<<"Tree is empty\n"; return;
	}
	struct tree *temp;
	temp=root;
	push(temp);
	while(1)
	{
		
	}
	
}*/
void maketree(struct tree *root)
{
	struct tree *l,*r;
	int lnode,rnode;
	l=(struct tree*)malloc(sizeof(struct tree));
	r=(struct tree*)malloc(sizeof(struct tree));
	cout<<"Enter left and right nodes of "<<(root->vertex)<<endl;	
	cout<<"Enter the left node(-1 to keep it null):"; cin>>lnode;
	if(lnode!=-1)
	{
		l->vertex=lnode;
		root->left=l;
	}
	cout<<"Enter the right node(-1 to keep it null):"; cin>>rnode;
	if(rnode!=-1)
	{
		r->vertex=rnode;
		root->right=r;
	}
	if(root->left!=NULL) maketree(l);
	if(root->right!=NULL) maketree(r);
}
int main()
{
	int n,r;
	struct tree *root;
	root=NULL;	
	cout<<"Enter the number of vertices:"; cin>>n;
	cout<<"Enter the root vertex:"; cin>>r;
	int count=0;	
	root=(struct tree*)malloc(sizeof(struct tree));
	root->vertex=r;	
	cout<<"Enter the edges:\n"; 
	maketree(root); cout<<endl;
	cout<<"preorder:\n";
	preorder(root);
	cout<<"\nPostorder:\n";
	postorder(root);
	cout<<"\nInorder:\n";
	inorder(root);
	return 0;
}
