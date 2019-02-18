#include<iostream>
#include<cstring>
using namespace std;


class complex 
{
	int real;
	int img;

public:
	complex()
	{
		real=img=0;
	}
	complex(int x)
	{
		real=img=x;
	}
	complex(double a,double b)
	{
		cout<<"double constructor\n";
		real=a; img=b;
	}
	complex(int a,int b)
	{
		real=a; img=b;
		cout<<"int constructor\n";
	}

	void adda(int a,int b)
	{
		cout<<"adda  integer function called \n";
		
	}
	void adda(char a,char b)
	{
		cout<<"adda  char function called \n";
	}


	friend complex add(complex a,complex b)
	{
		complex r(a.real+b.real,b.img+a.img);
		return r;
	}
	friend complex mul(complex a,complex b)
	{
			complex r;
			r.real=a.real*b.real - a.img*b.img;
			r.img = a.real*b.img + a.img*b.real;
			return r;
	}
	void display()
	{
		cout<<"complex no : "<<real<<"+i"<<img<<endl;
	}

};

int main(int argc, char const *argv[])
{
	
	complex c1(2),c2(2,3);
	complex m,ad;
	ad = add(c1,c2); 
	ad.display();
	m= mul(c1,c2);
	m.display();

	cout<<"\n\n";
	complex c(2,3);
	c.adda('A','B');

	return 0;
}
