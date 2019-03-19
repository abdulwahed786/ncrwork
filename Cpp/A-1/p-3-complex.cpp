// Write a C++ program to add two complex numbers. The class Complex contains
// three constructors.
// a. One with no parameter.
// b. With one parameter(Same value for real and imaginary part)
// c. With two parameters.
// d. A friend functions
// i. One to add two complex number by taking two reference variables of the class complex.
// ii. One to multipy two complex number by taking two reference
// variables of class complex

#include<iostream>
#include<cstring>
using namespace std;

class complex //complex class
{
	int real;
	int img;

public:
	complex()  //a. One with no parameter.
	{
		real=img=0;
	}
	complex(int x) // b. With one parameter(Same value for real and imaginary part)
	{
		real=img=x;
	}
	complex(int a,int b) //c. With two parameters.
	{
		real=a; img=b;
	}
	friend complex add(complex a,complex b) //friend func add two complex number by taking two reference variables 
	{
		complex r(a.real+b.real,b.img+a.img);
		return r;
	}
	friend complex mul(complex a,complex b) //friend func multipy two complex number by taking two reference 
	{
			complex r;
			r.real=a.real*b.real - a.img*b.img;
			r.img = a.real*b.img + a.img*b.real;
			return r;
	}
	void display() //display fucntion
	{
		cout<<"complex no : "<<real<<"+i"<<img<<endl;
	}

};

int main(int argc, char const *argv[])
{	
	complex c1(2),c2(2,3); //calling 2 diif constructors
	complex m,ad;
	ad = add(c1,c2); 
	ad.display();
	m= mul(c1,c2);
	m.display();
	return 0;
}


