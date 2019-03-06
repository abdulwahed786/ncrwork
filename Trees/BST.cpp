#include<bits/stdc++.h>
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
void levelorder(Node *root)
{
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(q.empty()==0)
	{
		Node *t=q.front();
		q.pop();
		if(t!=NULL)
		{
			if(t->left)
			q.push(t->left);
		if(t->right)
			q.push(t->right);
		cout<<t->data<<" ";

		}
		else 
		{
			if(q.empty()==0) // else it will got infite loop
				q.push(NULL); //push NULL hwhen we find null
			cout<<endl;
		}
		
	}
}
Node* findmax(Node *r)
{
	if(r==NULL)
	return NULL;
	while(r->right!=NULL)
	  r=r->right; 
   	return r;
}

Node* deletebst(Node *head,int ele)
{
	if(head->data == ele)
	{
		if(head->left==NULL && head->right==NULL)  //leaf
		{
			return NULL;
			//delete optional
		}
		else if(head->left==NULL || head->right==NULL)  // one child
		{
			Node *temp=head;
			if(head->left)
				head=head->left;
			else
				head=head->right;
			delete temp;
		}
		else  //two childs
		{
			// Node *temp = findmax(head->left);
			// head->data =  temp->data;
			// head->left = deletebst(head->left,temp->data);

			//or 
			Node *curr=head->left,*prev;
			while(curr->right!=NULL) //findinf rightmost max node
			{
				prev=curr;
				curr=curr->right;
			}
			head->data=curr->data;
			if(curr->left) //max nodes left exist 
			{
				prev->right=curr->left;
				delete curr;
			}
			else
			{
				prev->right=NULL;
				delete curr;
			}

		}

	}
	else if(head->data < ele)
	{
		head->left=deletebst(head->right,ele);
	}
	else
		head->right=deletebst(head->left,ele);
	return head;
}

void inorder(Node *head)
{
	if(head==NULL)
		return;
	inorder(head->left);
	cout<<" "<<head->data<<" ";
	inorder(head->right);
}
int height(Node *head)
{
	if(head==NULL)
		return -1;
	return max(height(head->left),height(head->right))+1;
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

	cout<<"level order : \n";
	levelorder(h);

	cout<<"height : "<<height(h)<<endl;

	cout<<"enter the ele to be deleted : ";
	int z; cin>>z;
	h=deletebst(h,z);

	cout<<"\nlevel order : \n";
	levelorder(h);

	cout<<"\ninorder of the tree \n";
	inorder(h);

	return 0;
}