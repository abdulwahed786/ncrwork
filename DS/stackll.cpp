#include<iostream>
using namespace std;

typedef struct n 
{
	int data;
	struct n *next;
} Node;

class LL
{
	Node *head;
public:
	LL()
	{
		head=NULL;
	}
	void insert_First(int e)
	{
		Node *temp=new Node;
		temp->data=e; temp->next=NULL;

		temp->next=head;
		head=temp;
	}
	void insert_Last(int e)
	{
		Node *temp=new Node;
		temp->data=e; temp->next=NULL;

		if(head!=NULL)
		{
			Node *curr=head;
			while(curr->next!=NULL)
				curr=curr->next;
			curr->next=temp;

		}
		else
		{
			head=temp;
		}
	}

	void insert_After(int find,int e)
	{
		Node *temp=new Node;
		temp->data=e; temp->next=NULL;

		if(head!=NULL)
		{
			Node *curr=head;
			while(curr!=NULL && curr->data!=find)
				curr=curr->next;
			if(curr)
			{
				temp->next=curr->next;
				curr->next=temp;
			}

		}
		else
		{
			head=temp;
		}
	}
	void insert_Before(int find,int e)
	{
		Node *temp=new Node;
		temp->data=e; temp->next=NULL;

		if(head!=NULL)
		{
			Node *curr=head;
			while(curr->next!=NULL && curr->data!=find)
				curr=curr->next;
			if(curr)
			{
				temp->next=curr->next;
				curr->next=temp;
			}
		}
		else
		{
			head=temp;
		}
	}

	int delete_First();
	int delete_Last();
	int delete_Before(int sele);
	int delete_After(int sele);
	void DisplayForward();
	void DisplayBackward();
	void reverse();
	friend void print(Node *);

};
//----------------------------------------
void LL::reverse()
{
	if(head!=NULL)
	{
		Node *curr=head,*prev=NULL,*temp=NULL;
		while(curr!=NULL)
		{
			temp=curr->next;
			curr->next=prev;
			prev=curr;
			curr=temp;
		}
		head=prev;
	}
}
int LL:: delete_After(int sele)
{
	int x=-999;
	if(head!=NULL)
	{
		if(head->next!=NULL)
		{
			Node *curr=head,*prev=NULL;
			while(curr!=NULL&&curr->data!=sele)
			{
				prev=curr;
				curr=curr->next;
			}
			if(curr->next!=NULL)
			{
				x=curr->data;
				prev->next=curr->next;
				delete curr;
			}
			else
			{
				//cout<<"no element to delete"<<endl;
			}
		}
	}
	return x;
}
int LL::delete_Before(int sele)
{
	int x=-999;
	if(head!=NULL)
	{
		if(head->next!=NULL)
		{
			Node *curr=head,*prev=NULL;
			while(curr->next!=NULL&&curr->next->data!=sele)
			{
				prev=curr;
				curr=curr->next;
			}
			if(curr->next!=NULL)
			{
				x=curr->data;
				if(prev!=NULL)
				prev->next=curr->next;
				else
				{
					head=curr->next;
				}
				delete curr;
			}
		}
	}
	return x;
}
int LL::delete_First()
{
	int x=-999;
	if(head!=NULL)
	{
		Node *temp=head;
		head=head->next;
		x=temp->data;
		delete temp;
	}
	return x;
}
int LL::delete_Last()
{
	int x=-999;
	if(head!=NULL)
	{
		if(head->next==NULL)
		{
			x=head->data;
			delete head;
			return x;
		}
		Node* curr=head;
		Node *temp=head;
		while(curr->next!=NULL)
		{
			temp=curr;
			curr=curr->next;
		}
		temp->next=NULL;
		x=curr->data;
		delete curr;
	}
	return x;
}



void LL::DisplayForward()
{
	if(head!=NULL)
	{
		Node *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	else
	{
		cout<<"the list is empty"<<endl;
	}
}
void print(Node *temp)
{
	if(temp)
	{
		print(temp);
		cout<<temp->data<<" ";
	}
}
void LL::DisplayBackward()
{
	print(head);
	cout<<endl;
}




int main()
{
	LL l;
	//stack using linked list
	//push=insert_First  pop=delete_First

	cout<<"enter number of elements to be inserted: ";
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int d;
		cout<<"enter data to push :";
		cin>>d; 
		l.insert_First(d);
	}  
	l.DisplayForward();

	// to pop 
	cout<<" pop : \n";
	l.delete_First();
	l.DisplayForward();

	cout<<" pop : \n";
	l.delete_First();
	l.DisplayForward();
	
	
	return 0;
}


