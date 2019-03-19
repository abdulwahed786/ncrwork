// Define string class with dynamic memory allocation for string. Define default
// constructor, parameterized constructors, copy constructor, destructor, Overload +,
// [], =, <<, >> operators. Observe the behavior of shallow copying and deep copying.

#include<iostream>
#include<cstring>
using namespace std;
class String
{
	//private section
	char *str;
	int len;
	public:
	//public section
		String()//default constructor
		{
			str=NULL;
			len=0;
		}
		String(char *s)// deep copy here
		{
			len=strlen(s);
			// s=(char *)malloc(sizeof(char)*(len+1));
			s=new char[len+1];
			strcpy(str,s);
		}
		String(const String &temp)// shallow copy goes here
		{
			str=temp.str;
			len=temp.len;
		}
		~String()//destructor
		{
		}
		//member functions declarations
		String operator+(String temp);
		char operator[](int index);
		friend ostream& operator<<(ostream &cout,String s);
		friend istream& operator>>(istream &cin,String &s);
		String operator=(String a);
};
//definitions of overloaded function
String String::operator+(String temp)
{
	String res;
	res.len=temp.len+len;
	cout<<res.len<<endl;
	// res.str=(char *)malloc(sizeof(char)*(res.len+1));
	res.str=new char[res.len+1];
	int i;
	for(i=0;i<len;i++)
		res.str[i]=str[i];
	for(int j=0;j<temp.len;j++,i++)
		res.str[i]=temp.str[j];
	res.str[i++]='\0';  //adding null character
	return res;
}
char String::operator[](int index)
{
	return this->str[index];
}
ostream& operator<<(ostream &cout,String s)
{
	cout<<s.str<<endl;
	return cout;
}
istream& operator>>(istream &cin,String &s)
{
	char temp[50];
	cin>>temp;
	s.str=(char *)malloc(sizeof(char)*(strlen(temp)+1));
	strcpy(s.str,temp);
	s.len=strlen(temp)+1;
	return cin;
}
String String::operator=(String a)
{
	str=(char *)malloc(sizeof(char)*(strlen(a.str)+1));
	strcpy(str,a.str);
	len=a.len;
	return *this;
}
int main()
{
	String a1,a2,a3;
	cout<<"enter a string :";
	cin>>a1;
	a2=a1;
	cout<<a1;
	cout<<a2;
	// a2="-aaaaa";
	cout<<a2[2]<<endl;

	a3 = (a1+a2);
	cout<<"overloading + operator\n";
	cout<<a3<<endl;

	return 0;
}