// Write a generic function template to carry out linear search with the following
// a. Demonstrate it for int, double and float data types
// b. Use default arguments in the template function
// c. Write an explicit specialization of the generic template for char* data type
// d. Demonstrate it for complex data type

#include<iostream>
using namespace std;
#include <cstring>


class Complex
{
	int real,imag;
	public:
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
		friend istream& operator>>(istream& cin,Complex &b);//overloading cin
};
istream& operator>>(istream& cin,Complex &x)
{
	cin>>x.real>>x.imag;
	return cin;
}


template<class T>// template declaration
int linear_search(T arr[],int size,T ele)// template function to implement search
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==ele)
			return i;
	}
	return -1;
}

int linear_search(const char *arr[],int size,char eles[20])//search function for char * type data
{
	for(int i=0;i<size;i++)
	{
		if(strcmp(arr[i],eles)==0)
			return i;
	}
	return -1;
}
int main()
{
	// integer array
	int integerarray[10];
		for(int i=0;i<10;i++)
		integerarray[i]=(int)i;
	int pos=linear_search<int>(integerarray,10,3);
	if(pos==-1)
	{
		cout<<"element not found\n";
	}
	else
	{
		cout<<"Element found at "<<pos<<endl;
	}

	//float array
	float floatarray[10];
	for(int i=0;i<10;i++)
		floatarray[i]=(float)i;
	int pos2=linear_search<float>(floatarray,10,3.0f);
	if(pos2==-1)
	{
		cout<<"not found\n";
	}
	else
	{
		cout<<"Element found at "<<pos2<<endl;
	}

	// double array
	double doublearrray[10];
	for(int i=0;i<10;i++)
		doublearrray[i]=(double)i;
	int pos3=linear_search<double>(doublearrray,10,5.0);
	if(pos3==-1)
	{
		cout<<"not found\n";
	}
	else
	{
		cout<<"found at "<<pos3<<endl;
	}


	//char* arrray
	const char *arr[4]={"abdul","wahed","xyz","abc"};
	char eles[20]="abdul";
	int pos4=linear_search(arr,4,eles);
	if(pos4==-1)
	{
		cout<<" not found\n";
	}
	else
	{
		cout<<"found at "<<pos4<<endl;
	}

	//  complex objects
	Complex c(10,5),ar[5];
	cout<<"enter the complex numbers :\n";
	for(int i=0;i<5;i++)
	{
		cin>>ar[i];
	}

	int pos5=linear_search(ar,5,c);
	if(pos5s==-1)
	{
		cout<<"not found\n";
	}
	else
	{
		cout<<"found at "<<pos5<<endl;
	}

	return 0;
}