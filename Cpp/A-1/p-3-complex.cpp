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
	complex(int a,int b)
	{
		real=a; img=b;
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
	return 0;
}


