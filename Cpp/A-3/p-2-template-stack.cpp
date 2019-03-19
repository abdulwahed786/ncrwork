// Define a template stack class. Using this template class, create stack objects of int,
// float, char* and complex type. Include exception-handling functionality.

#include <iostream>
using namespace std;


template<class T>// template declaration
class Stk  // stack class
{
  int top;
  T *s;
  int size;
public:
	Stk() //constructor
	{
		top=-1;
		size=0;
		s=NULL;
	}
	void setsize(int x) //setting size of stack
	{
		size=x;
		s=new T[x];
		try
		{
			if(s==NULL)
			{
				throw "could not allocate memory";
			} 
		}
		catch(char *st)
			{
				cout<<st<<endl;
				exit (0);
			}	
	}
	bool isFull() //checking if stack is full
	{
		return top==(size-1);
	}
	bool isEmpty() 
	{
		return top==-1;
	}
	void push(T k)
	{
		try
			{
				if(isFull())
				{
					cout<<"stack is full\n";
					throw "can't push into the stack";
				}
				else{
					s[++top]=k;
				}
				
			}
			catch(const char *st)
			{
				cout<<st<<endl;
			}
	}
	T pop()
	{
		try
			{
				if(isEmpty())
				{
					cout<<"\nstack is empty\n";
					throw "can't pop from the stack";
				}
				else{
					return s[top--];
				}
				
			}
			catch(const char *st)
			{
				cout<<st<<endl;
				exit (0);
			}
			// return 0; //to remove warning of no return 
	}

	T peek()
	{
		try{
				if(isEmpty())
				{
					cout<<"stack is empty\n";
					throw "No top in stack";
					// return;
				}
				return s[top];
			}
			catch(const char *st)
			{
				cout<<st<<endl;
				exit (0);
			}
			// return -999;
	}

	void display()
	{
		cout<<"Stack contents are :";
		for(int i=0;i<=top;i++)
		{
			cout<<" ";
			cout<<s[i];
			cout<<" ";
		}
	}
	~Stk()
	{
		delete s;
	}

};


class Complex
{
	
	public:
		int real,imag;
		Complex()//default constructor
		{
			real=imag=0;
		}
		Complex(int x,int y)// parameterized constructor
		{
			real=x;
			imag=y;
		}
		Complex(const Complex &b)//copy constructor
		{
			real=b.real;
			imag=b.imag;
		}
		~Complex()//destructor
		{
			//cout<<"destructor";
		}
		bool operator==(const Complex &a)// overloading ==
		{
			if(real==a.real&&imag==a.imag)
				return true;
			else
				return false;
		}
		friend istream& operator>>(istream& cin,Complex &x);//overloading cin
		friend ostream& operator<<(ostream& cout,Complex x);//overloading cin
};
istream& operator>>(istream& cin,Complex &x)
{
	cin>>x.real>>x.imag;
	return cin;
}
ostream& operator<<(ostream& cout,Complex x)
{
	cout<<x.real<<" +i "<<x.imag<<endl;
	return cout;
}

void choiceprint()
{
		cout << "choose the options from below ::  " << endl;
		cout << "1.push " << endl;
		cout << "2.pop " << endl;
		cout << "3.top element" << endl;
		cout << "4.Check stack is full" << endl;
		cout << "5.Check stack is empty" << endl;
		cout << "6.display the elemnets of the stack" << endl;
		cout << "7.exit";
		cout << endl;
		cout << "ENTER YOUR CHOICE ::  ";	
}

void Stackforint()
{
	int a;
	cout<<"enter the size  of the stack :";
	cin>>a;

	Stk<int> obj;

	obj.setsize(a);
	int choice;
	int input;
	while(1)
	{
		choiceprint();
		cin >> choice;
		switch(choice)
		{
			case 1: cout<<"enter the element  to push\n";
					cin>>input;
					obj.push(input);
					break;
			case 2: cout<<"Poped element : \n";
					cout<<obj.pop();
					cout<<endl;
					break;
			case 3: cout<<"top of stack: \n";
					cout<<obj.peek();
					cout<<endl;
					break;
			case 4: if(obj.isFull())
						cout<<"stack full\n";
					else
						cout<<"stack  not full\n";
					break;
			case 5: if(obj.isEmpty())
						cout<<"stack  empty\n";
					else
						cout<<"stack  not empty\n";
					break;
			case 6: obj.display();
					cout<<endl;
					break;
			case 7: return ;
		}
	}
	return ;
}

void Stackforfloat()
{
	int a;
	cout<<"enter the size  of the stack :";
	cin>>a;

	Stk<float> obj;

	obj.setsize(a);
	
	int choice;
	float input;
	while(1)
	{
		choiceprint();
		cin >> choice;
		switch(choice)
		{
			case 1: cout<<"enter the element  to push\n";
					cin>>input;
					obj.push(input);
					break;
			case 2: cout<<"Poped element : \n";
					cout<<obj.pop();
					cout<<endl;
					break;
			case 3: cout<<"top of stack: \n";
					cout<<obj.peek();
					cout<<endl;
					break;
			case 4: if(obj.isFull())
						cout<<"stack full\n";
					else
						cout<<"stack  not full\n";
					break;
			case 5: if(obj.isEmpty())
						cout<<"stack  empty\n";
					else
						cout<<"stack  not empty\n";
					break;
			case 6: obj.display();
					cout<<endl;
					break;
			case 7: return ;
		}
	}
	return ;
}

void Stackforchar()
{
	int a;
	cout<<"enter the size  of the stack :";
	cin>>a;

	Stk<char> obj;

	obj.setsize(a);
	
	int choice;
	char input;
	while(1)
	{
		choiceprint();		
		cin >> choice;
		switch(choice)
		{
			case 1: cout<<"enter the element  to push\n";
					cin>>input;
					obj.push(input);
					break;
			case 2: cout<<"Poped element : \n";
					cout<<obj.pop();
					cout<<endl;
					break;
			case 3: cout<<"top of stack: \n";
					cout<<obj.peek();
					cout<<endl;
					break;
			case 4: if(obj.isFull())
						cout<<"stack full\n";
					else
						cout<<"stack  not full\n";
					break;
			case 5: if(obj.isEmpty())
						cout<<"stack  empty\n";
					else
						cout<<"stack  not empty\n";
					break;
			case 6: obj.display();
					cout<<endl;
					break;
			case 7: return ;
		}
	}
	return ;
}

void Stackforcomplex()
{
	int a;
	cout<<"enter the size  of the stack :";
	cin>>a;

	Stk<Complex> obj;

	obj.setsize(a);
	
	
	int choice;
	Complex input;
	while(1)
	{
		choiceprint();
		cin >> choice;
		switch(choice)
		{
			case 1: cout<<"enter the element  to push\n";
					cin>>input;
					obj.push(input);
					break;
			case 2: cout<<"Poped element : \n";
					cout<<obj.pop();
					cout<<endl;
					break;
			case 3: cout<<"top of stack: \n";
					cout<<obj.peek();
					cout<<endl;
					break;
			case 4: if(obj.isFull())
						cout<<"stack full\n";
					else
						cout<<"stack  not full\n";
					break;
			case 5: if(obj.isEmpty())
						cout<<"stack  empty\n";
					else
						cout<<"stack  not empty\n";
					break;
			case 6: obj.display();
					cout<<endl;
					break;
			case 7: return ;
		}
	}
	return ;
}

int main(int argc, char const *argv[])
{
	while(1)
	{
		cout<<"enter the data type of the stack\n";
		cout<<"1. int\n2.float\n3.character\n4.complex\n5.exit\n choice:: ";
		int nChoice;
		cin>>nChoice;
		switch(nChoice)
		{
			case 1: cout<<"\n integer stack \n";
					Stackforint(); //integer stack
					break;

			case 2: cout<<"\n float stack \n";
					Stackforfloat(); //float stack
					break;

			case 3: cout<<"\n char stack \n";
					Stackforchar();
					break;

			case 4: cout<<"\n complex stack \n";
					Stackforcomplex(); //complex no stack
					break;

			case 5: exit(0);
					break;
		}
	}


	// cout<<"\n integer stack \n";
	// Stackforint(); //integer stack

	// cout<<"\n float stack \n";
	// Stackforfloat(); //float stack

	// cout<<"\n char stack \n";
	// Stackforchar();  //char * stack

	// cout<<"\n complex stack \n";
	// Stackforcomplex(); //complex no stack

	// cout<<"enter the size  of the stack :";
	// cin>>a;

	// Stk<int> st;
	// st.setsize(a);

	// st.push(10);
	// st.push(20);
	// cout<<"pop : "<<st.pop()<<" \n";
	// cout<<st.pop()<<" ";
	// // st.pop()<<" ";

	// st.push(100);
	// st.push(200);
	// cout<<" top element "<<st.peek()<<" \n";

	// cout<<"\n enter the size  of the stack for complex stack :";
	// cin>>a;
	// Stk<Complex> sc;
	// sc.setsize(a);

	// Complex c1,c2;
	// cout<<"\n enter 2 complex numbers : ";
	// cin>>c1>>c2;
	// sc.push(c1);
	// sc.push(c2);
	// cout<<"\n pop from complex stack: "<<sc.pop();


	

	return 0;
}