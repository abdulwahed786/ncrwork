#include <iostream>
#include<ctype.h>
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



int main(int argc, char const *argv[])
{
	int a;
	cout<<"enter the size  of the stack :";
	cin>>a;

	Stk<int> st;
	// st.getsize(a);

	cout<<" Enter the string  : ";
	string s; cin>>s;
	int l=s.length();
	st.getsize(l);

	int r=0;

	// int flag=0;//to mark 
	for(int i=0;i<l;i++)
	{
		char ch=s[i];
		if(isdigit(ch))
		{
			int k=ch-'0';
			// st.push(ch-'0');
			while(s[++i]!='@')
			{
				k= k*10+(s[i]-'0');
				// i++;
			}
			cout<<"k= "<<k<<" ";
			st.push(k);
			i--;
			continue;
		}
		else if(ch== '+' || ch=='-' || ch=='*' || ch=='/') //operator
		{
			int a,b,c;
			b=st.pop();
			a=st.pop();
			if(ch=='+')
				c=a+b;
			else if(ch=='-')
				c=a-b;
			else if(ch=='*')
				c=a*b;
			else if(ch=='/')
				c=a/b;

			st.push(c);
		}
		else if(ch=='@')
			continue;
		else
		{
			// cout<<"invaid input\n";
			// return 0;
			// st.push(ch);
		}
		
	}//for loop

	if(st.isEmpty()==0)
		r= st.pop();
		
		cout<<"Postfix exp value : "<<r;

	return 0;
}