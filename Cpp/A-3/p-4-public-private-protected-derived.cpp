// Write 3 separate programs to demonstrate the different types of derivations, public,
// private and protected. Explain using appropriate comments the access of inherited
// members

#include <iostream>
using namespace std;


class A
{
	public:
		int x_a;  //public
	protected:
		int y_a; //protected
	private:
		int z_a;  //private

	public:
		A() //constructor
		{
			x_a = 1;
			y_a= 2;
			z_a = 3;
		}
};

class B : public A   //public derivation
{
	public:
		void display()
		{
			cout << "\n X = " << x_a;
			cout << "\n Y = " << y_a;
			
			//Private member are not inherited in private derivation
			//cout << "\n Z  = " << z_a;
		}
};
class C: protected A  //protected derivation
{
public:
	void display()
	{
		// public and protected members are  inherited
		cout << "\nX = " << x_a;
		cout << "\nY = " << y_a;
		//Private member are not inherited in private derivation
			//cout << "\n Z  = " << z_a;
	}
};

class D : private A  //private derivation
{
public:
	void display()
	{
		// X and Y are Private in D
		cout << "\n  X = " << x_a;
		cout << "\n  Y = " << y_a;
		// Private member Cannot be accessed
		//cout << "\n Z = " << z_a;
		cout << "\n\n";
	}
};

class E : protected C  //protected further inherited
{

public:
	void display()
	{
		// A's public and protected members are inherited as portected
		// public and protected members are  inherited
		cout << "\nX = " << x_a;
		cout << "\nY = " << y_a;
		//Private member are not inherited in private derivation
			//cout << "\n Z  = " << z_a;
	}
	
};
int main()
{
	A a;
	cout << "Acccessing base class A public members : \n";
	cout<<" X = " << a.x_a<<"\n";
	cout << " Y and Z cannot be accessed as Y is Protected and Z is Private\n\n";
	// Y and Z cannot be accessed as Y is Protected and Z is Private
	//cout << a.y_a<<endl;
	//cout << a.z_a <<endl;


	
	B pub;
	cout << " When Derived class is Public";
	pub.display();

	C pro;
	cout << " When Derived class is Protected";
	pro.display();

	D pri;
	cout << " When Derived class is Protected";
	cout << " only public and protected members are derived as PRIVATE in class\n\n";
	pri.display();
	
	E propro;
	cout << " When Derived class is Protected from protected";
	cout << " only public and protected members are derived as  in class\n\n";
	propro.display();

	
	return 0;
}
