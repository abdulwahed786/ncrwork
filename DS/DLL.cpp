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

	int deleteBeginning();
	int deleteLast();
	int deleteBefore(int sele);
	int deleteAfter(int sele);
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
int LL:: deleteAfter(int sele)
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
int LL::deleteBefore(int sele)
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
int LL::deleteBeginning()
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
int LL::deleteLast()
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
	while(1)
	{
		cout<<"enter the operation you want"<<endl;
		cout<<"1. Insert at beginning \n2. insert at end\n3. insert before an element\n4. insert after an element\n";
		cout<<"5. delete at beginning \n6. delete at end\n7. delete before an element\n8. delete after an element\n";
		cout<<"9. Display\n10.reverse\n11.exit\n";
		int choice;
		cin>>choice;
		int ele,sele;
		switch(choice)
		{
			case 1:
				cin>>ele;
				l.insert_First(ele);
				break;
			case 2:cin>>ele;
				l.insert_Last(ele);
				break;
			case 3:
				cin>>ele>>sele;
				l.insert_Before(sele,ele);
				break;
			case 4:
				cin>>ele>>sele;
				l.insert_After(sele,ele);
				break;
			case 5:
				ele=l.deleteBeginning();
				if(ele!=-999)
					cout<<"deleted element is "<<ele<<endl;
				else
					cout<<"element not found to delete "<<endl;
				break;
			case 6:
				ele=l.deleteLast();
				if(ele!=-999)
					cout<<"deleted element is "<<ele<<endl;
				else
					cout<<"element not found to delete "<<endl;
				break;
			case 7:
				cin>>sele;
				ele=l.deleteBefore(sele);
				if(ele!=-999)
					cout<<"deleted element is "<<ele<<endl;
				else
					cout<<"element not found to delete "<<endl;
				break;
			case 8:
				cin>>sele;
				ele=l.deleteAfter(sele);
				if(ele!=-999)
					cout<<"deleted element is "<<ele<<endl;
				else
					cout<<"element not found to delete "<<endl;
				break;
			case 9:
				cout<<"enter the choice\n";
				cout<<"\t1.DisplayForward\n\t2.DisplayBackward\n";
				int x;
				cin>>x;
				if(x==1)
				{
					l.DisplayForward();
				}
				else
					l.DisplayBackward();
				break;
			case 10:
				l.reverse();
				cout<<"reversed list is"<<endl;
				l.DisplayForward();
				break;
			case 11:
				exit(0);
		}	
	}
	return 0;
}


