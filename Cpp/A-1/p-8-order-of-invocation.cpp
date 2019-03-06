#include<iostream>
using namespace std;
class Emp
{
	int x,y;
	string name;
	//public section
	public:
		
		Emp()//default constructor
		{
			cout<<"In default constructor"<<endl;
			string s;
			cout<<"enter the name:";
			cin>>s;
			name=s;
		}
		Emp(int a,int b)//parameterized constructor
		{
			cout<<"in parameterized constructor"<<endl;
			x=a;
			y=b;
			string s;
			cout<<"enter the name:";
			cin>>s;
			name=s;
		}
		Emp(const Emp &b)//copy constructor
		{
			cout<<"in copy constructor"<<endl;
			x=b.x;
			y=b.y;
			//string str;
			name=b.name;
		}
		friend void display_byval(Emp e){// call by value;
			cout<<"Call by value " ;
			cout<<e.name<<endl;
		}

		friend void display_byref(Emp &e){// call by reference;
			cout<<"Call by reference ";
			cout<<e.name<<endl;
		}

		~Emp()//destructor
		{
			cout<<"In destructor of \n"<<endl;
			cout<<name<<endl;
		}
};
// void func()// function to see active objects and deleted objects after the execution of function
// {	
// }
int main()
{
	//func();
	Emp e1,e2(100,200);
	// displaying sizes of objects
	cout<<sizeof(e1)<<" "<<sizeof(e2)<<endl;
	Emp e3(e2);
	Emp e4=e2; //copy constructor is called
	Emp e5;
	e5=e3;   //normal assignment, nothing is called
	cout<<sizeof(e3)<<endl;
	display_byval(e1);  //copy constructor is called
	display_byref(e1);
	
}