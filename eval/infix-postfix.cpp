#include <iostream>
#include<ctype.h>
using namespace std;

#define STACKSIZE 200

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
			cout<<"pop  stack is empty \n";
			return (t)0;
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
			cout<<"peek stack is empty\n ";
			return (t)0;
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

int pred(char c)
{
	if(c=='+' || c=='-')
		return 1;
	else if(c=='*' || c=='/')
		return 2;
	else
		return 0;
}



int main(int argc, char const *argv[])
{
	int a=STACKSIZE;
	// cout<<"enter the size  of the stack :";
	// cin>>a;

	Stk<char> st;
	// st.getsize(a);

	cout<<" Enter the string  : ";
	string s; cin>>s;
	int l=s.length();
	st.getsize(l);

	string r="";

	int flag=0;//to mark 
	int flagOp=0; //to check if op was before
	for(int i=0;i<l;i++)
	{

		char ch=s[i];
		if(isdigit(ch))
		{
			r+=ch;
			if(i<l && !isdigit(s[i+1]))
				r+='@'; //add delimiter
		}
		else if(ch== '(' || ch=='{' || ch=='[') //opening 
		{
			st.push(ch); //blindly push opeing
		}
		else if(ch== ')' || ch=='}' || ch==']')  //closing
		{
			char top=st.peek();
			while(!(top== '(' || top=='{' || top=='['))
			{
				r+=st.pop();
				top=st.peek();
			}
			st.pop();
		}
		else if(ch== '+' || ch=='-' || ch=='*' || ch=='/') //operator
		{
			int incom=pred(ch);
			int ptop= pred(st.peek());
			if(incom>ptop)
			{
				st.push(ch);
			}
			else
			{
				r+=st.pop();
				ptop= pred(st.peek());
				while(incom<=ptop)
					{
						r+=st.pop();
						ptop= pred(st.peek());
					}	

				st.push(ch);
			}
			
		}
		else //delimiter or other 
		{
			// int x;
			// if(ch==del)
			// {
			// 	continue;
			// }
			// else
			// {

			// }
			// st.push(ch);
		}
		
		
		cout<<" i= "<<i<<" r="<<r<<endl;
	}//for loop

	while(st.isEmpty()==0)
		r+=st.pop();
		
		cout<<"Postfix exp : "<<r;

	return 0;
}