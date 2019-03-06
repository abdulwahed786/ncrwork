#include<iostream>
using namespace std;


class Node 
{
public:
	int data;
	Node *left,*right;
};
Node* insertbst(Node *h,int e)
{
	if(h==NULL)
	{
		h=new Node;
		h->data=e;
		h->left=h->right=NULL;
		// return h;
	}
	else if(e <= h->data)
	{
		h->left=insertbst(h->left,e);
	}
	else
		h->right=insertbst(h->right,e);
	return h;
}

void inorder(Node *head)
{
	if(head==NULL)
		return;
	inorder(head->left);
	cout<<" "<<head->data<<" ";
	inorder(head->right);
}


int main()
{
	int n; 
	cout<<"enter the number elements to be inserted in the tree :";
	cin>>n;
	Node *h=NULL;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		h=insertbst(h,x);
	}
	cout<<"inorder of the tree \n";
	inorder(h);

	return 0;
}