#include <iostream>
using namespace std;

template <class t>
class Stk
{
  t top;
  t *s;
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
		s=new t[x];
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
	void push(t k)
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
	t pop()
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
	t peek()
	{
		if(!isEmpty())
		{
			return s[top];
		}
		else
		{
			cout<<"stack is empty";
			return (t)255;
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

	Stk<char> st;
	// st.getsize(a);

	cout<<" Enter the string  : ";
	string s; cin>>s;
	int l=s.length();
	st.getsize(l);

	int flag=0;//to mark 
	for(int i=0;i<l;i++)
	{
		char c=s[i];
		switch (c)
		{
			case '(':
			case '{':
			case '[':
			 {
			 	if(!st.isFull())
			 		st.push(c);
			    else
			    {
			    	flag=1;
			    	break;
			    }
			 }
			 break;

			 case ')':
			 case '}':
			 case ']':
			   {
				   	 if(!st.isEmpty())
				   	 {
				   	   char tp=st.peek();
				   	   if( (c== ')' && tp=='(' ) ||   (c== '}' && tp=='{' )   ||  (c== ']' && tp=='[' )  )
				   	   {
				   	 	st.pop();
				   	   }
				   	   else
				   	  {
				   	 	flag=1;
				   	 	break;
				   	   }

				   	 }//if
				   	 else
				   	 {
				   	 	flag=1;
				   	 	break;
				   	 }

			   }
			   default:
			   // flag=1;
			   break;

		}
		if(flag==1)
		{
			cout<<"unbalanced paranthesis \n";
			return 0;
		}
	}//for loop
		cout<<" String is Balanced \n";

	return 0;
}