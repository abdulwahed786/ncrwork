// define linkedlist class
// 1. insert at nth position in linkedlist
// 2. reverse the linkedlist
// 3. print fwd
// 4. print reverse
// 5. delete node with particlar pos 

#include<iostream>
using namespace std;
class Node  //node class
{
	public: 
		int data;
		Node *next;
		Node(int d)
		{
			data=d;
			next=NULL;
		}
};

class linkedlist //linkedlsit class
{
	public:

	Node *head;
	linkedlist()
	{
		head=NULL;
	}


	Node* insert(Node *head,int pos,int d) //pos starts from 1
	{
		if(head==NULL)//first insertion
		{
			head=new Node(d);
			head->next=NULL;
			if(head==NULL)
				{ cout<<"error mem\n"; return NULL;}
			return head;
		}

		if(pos==1)
		{
			Node *temp=new Node(d);
			temp->next=head;
			return temp;
		}



		Node *p=head,*q;
		Node *newNode=new Node(d);

		int k=1;
		while((p!=NULL) && (k<pos))		// p is place for insertion | q will be at pos-1 | starts from k=1	 
		{								  
			k++;						
			q=p;
			p=p->next;
		}
		if(p==NULL && k<pos)
		 {
		 	cout<<"invalid input\n ";
		 	return NULL;
		 }				
		q->next=newNode;   
		newNode->next=p;

		return head;

	}  

	void deletell(int d)
	{
		if(head==NULL)
		{
			cout<<"\n cannot delete ll empty \n";
			return ;
		}

		if(head->data==d)
		{
			Node *temp=head;
			head=head->next;
			delete temp;
			return;
		}

		Node *p=head,*q;
		
		while((p!=NULL) && (p->data!=d))		// p is place for insertion | q will be at pos-1 | starts from k=1	 
		{								  						
			q=p;
			p=p->next;
		}	
		if(p->data==d)			
			q->next=p->next; 
		else
		{
			cout<<"element not found \n";
			return ;
		}
		delete p;


	}

	Node* reversell(Node* head) 
	{
		Node *temp=NULL, *nextNode=NULL;   // (temp head(points) nextnode) slide
		while(head!=NULL)
		{
			nextNode=head->next;
			head->next=temp;				//head reverses links to temp
			temp=head;
			head=nextNode;
		}
		return temp;
	}

	void printfwd(Node *head)
	{
		cout<<"\n printing forward : \n";
		Node *curr=head;
		while(curr)
		{
			cout<<curr->data<<"   ";
			curr=curr->next;
		}
	}

	void printrev(Node *head)
	{
		// cout<<"\n printing backward : \n";
		// Node *curr=head;
		
		if(head==NULL)
			return ;
		printrev(head->next);
		cout<<head->data<<" ";
	}



};

int main()
{
	linkedlist ll;

	while(1)
	{
		cout<<"ENTER CHOICE : \n 1. Insertion at P \n 2.reverseLL \n 3.print forward \n 4. print backward \n 5. deletion \n 6. exit\n Enter your CHOICE:  ";

		int ch; cin>>ch;
		switch(ch)
		{

			case 1:
			  cout<<"\n enter position to inserted (1 to -)  and value : ";
			  int p; cin>>p; int d; cin>>d;
			 
			  	ll.head= ll.insert(ll.head,p,d);
			  	cout<<"\ninserted\n";
			  break;

			case 2:
			 ll.head = ll.reversell(ll.head);
			 cout<<"\n reversed \n";
			 break;

			case 3:
			ll.printfwd(ll.head);
			break;

			case 4 :
			ll.printrev(ll.head);  
			break;

			case 5:
			cout<<"\n enter the element to be deleted : ";
			int val; cin>>val;
			ll.deletell(val);
			cout<<"\ndeleted\n";
			break;

			case 6:
			exit(0);
			break;
		}


	}


	return 0;
}































