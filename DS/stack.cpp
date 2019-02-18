#include <iostream>
using namespace std;

class Stk
{
  int top;
  int *s;
  int size;
public:
	Stk()
	{
		top=-1;
		size=0;
		s=NULL;
	}
	void getsize(int x)
	{
		size=x;
		s=new int[x];
		// if() 
	}
	bool isFull()
	{
		return top==(size-1);
	}
	bool isEmpty()
	{
		return top==-1;
	}
	void push(int k)
	{
		if(!isFull())
		{
			s[++top]=k;
		}
		else
		{
			cout<<"Stack is full";
		}
	}
	int pop()
	{
		if(!isEmpty())
		{
			return s[top--];
		}
		else
		{
			cout<<"satck is empty";
			return -99999;
		}
	}
	int peek()
	{
		if(!isEmpty())
		{
			return s[top];
		}
		else
		{
			cout<<"satck is empty";
			return -99999;
		}
	}
	void display()
	{
		cout<<"Stack contents are :";
		for(int i=0;i<=top;i++)
		{
			cout<<" "<<s[i]<<" ";
		}
	}
	~Stk()
	{
		delete s;
	}

};



int main(int argc, char const *argv[])
{
	int a;
	cout<<"enter the size  of the stack :";
	cin>>a;

	Stk st;
	st.getsize(a);

	st.push(10);
	st.push(20);
	cout<<"pop : "<<st.pop()<<" \n";
	cout<<st.pop()<<" "<<st.pop()<<" ";

	st.push(100);
	st.push(200);
	cout<<" top element "<<st.peek()<<" \n";


	return 0;
}