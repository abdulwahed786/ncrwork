// Write a program to demonstrate hybrid inheritance with virtual classes using the
// following classes,
// class person: base class
// data members: name, age
// class physique: derived virtually from person
// data members: height, weight
// class family: derived virtually from person:
// data members:numChildren, religion
// class employee derived from physique & family
// data members: empno, salary.


#include<iostream>
using namespace std;

class person  // base classs
{
	public:
		string name;
		int age;
		person()
		{
			name="aw";
			age=21;
		}
		void displayn()
		{
			cout<<name<<"'person age is "<<age<<endl;
		}
};

class physique : virtual public person  //derived from person (virtual base class)
{
	public:
		int height;
		int weight;
		physique()
		{
			height=10;
			weight=50;
		}
		void displayp()
		{
			//displayn();
			cout<<"the person height and weight are "<<height<<" "<<weight<<endl;
		}
};
class family: virtual public person //derived from person (virtual base class)
{
	public:
		int noofChildren;
		string religion;
		family()
		{
			noofChildren=11;
			religion="None";
		}
		void displayf()
		{
			
			cout<<"the number of children are "<<noofChildren<<" and religion is "<<religion<<endl;
		}
};
class employee: public physique, public family //two parent classes
{
	public:
		int emno;
		float salary;
		employee()
		{
			emno=79;
			salary=708060.0f;
		}
		void displaye()
		{
			displayn();
			displayp();
			displayf();
			cout<<"the employee number is "<<emno<<" salary is "<<salary<<endl;
		}
};
int main()
{
	employee obj1; // calling employee display function
	
	obj1.displaye();
	
	return 0;
}