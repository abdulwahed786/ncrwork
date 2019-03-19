//  create my_string class
//  char * name and int len 
//  defaukt cons , parameterrized and copy with deep copy
//  destructor
//  overload +,<,<<, >> 
//  friend func takes an array of objects of my_string class and sorts them in asc order using bubble sort
// 6.  in main function test functionality of above class

#include<iostream>
using namespace std;
#include<cstring>

class my_string  //class my_string
{

	public:

	char *name;
	int len;

	my_string()//default costructor
	{
		name= new char[0];
		len=0;
		strcpy(name,"");

		cout<<name<<endl;
	}
	my_string(char *s)//parameterrized costructor
	{
		len=strlen(s);
		name= new char[len+1];
		// for(int i=0;i<len;i++)
		// 	name[i]=s[i];
		// name[len]='\0';
		strcpy(name,s);

		// cout<<name<<endl;
	}

	my_string(const my_string &s2) //copy constructor
	{
		len=s2.len;
		name= new char[len+1];
		strcpy(name,s2.name); //deep copy
	}
	~my_string()  //destructor
	{
		delete name;
	}
	friend ostream& operator<<(ostream &cout,my_string ms);
	friend istream& operator>>(istream &cin,my_string &ms);

	

	my_string operator+(my_string ms) //overload + 
	{
		my_string res;
		res.len=len+ms.len;
		res.name=new char[res.len+1];

		int i;
		for(i=0;i<len;i++)
			res.name[i]=name[i];
		for(int j=0;j<ms.len;j++,i++)
			res.name[i]=ms.name[j];
		res.name[i++]='\0';  //adding null character
		return res;

	}


	bool operator<(my_string &ms) //overload <
	{
		if(strcmp(name,ms.name)<0)
			return true;
		else
			return false;
	}
	my_string operator=(my_string m)
	{
		len=m.len;
		name=new char[len+1];
		strcpy(name,m.name);
		return *this;
	}

	friend void mysort(my_string m[],int n)
	{
		for(int i=0;i<n;i++)
		{
			
			for(int j=0;j<n-i-1;j++)
			{

				if(strcmp(m[j].name,m[j+1].name)>0)  //a[j]>a[j+1]
				{ 
					//swap m[j] and m[j+1]
					my_string temp;
					temp.len=m[j].len;
					strcpy(temp.name,m[j].name);

					m[j]=m[j+1];
					m[j+1]=temp;
					
				}
				
				
			}
		}

		// for(int i=0;i<n;i++)
		// {
		// 	cout<<m[i].name<<" "; 
		// }
	} //sort

};
	
	istream& operator>>(istream &cin,my_string &ms) //overloading >> operator
	{
		cout<<"\n enter the string  string: ";
		// cin>>ms.len;
		char n[20];
		cin>>n;
		ms.name=new char[strlen(n)+1];
		strcpy(ms.name,n);
		ms.len=strlen(ms.name);
		return (cin);
	}
	 ostream& operator<<(ostream &cout,my_string ms) //overloading << operator
	{
		cout<<" "<<ms.name<<" ";
		cout<<ms.len<<endl;
		return (cout);
	}

int main()
{
	cout<<"1. default constructor : \n";
	my_string m; //default cons

	cout<<"\n 2. param constructor : m2\n";
	char st[10]; 
	cout<<"enter string:";
	cin>>st;
	my_string m2(st); //param cons
	cout<<"param constructor"<<m2<<endl; //overloaded <<

	cout<<"\n 3.cin my_string on m \n";
	cin>>m;
	cout<<m<<endl;

	//copy cons
	my_string m3(m2);
	cout<<"\n 4. after copy cons on m3 \n";
	cout<<"m3="<<m3<<endl;

	cout<<"5. operator < on (m<m2)\n";
	cout<<(m<m2)<<endl;

	cout<< "\n 6. overload ( + ) operation: on m4 ";
	my_string m4=m2+m;
	cout<<"  m4 ="<<m4<<endl; 	

	cout<<"\n 7.  overload ( = ) operator\n";
	my_string m7=m4;
	cout<<"m7 ="<<m7<<endl;

	cout<<" \n 8. sort opertion \n";
	cout<<"enter no of strings to sort\n";
	int x; cin>>x;
	my_string mi[x];
	for(int i=0;i<x;i++)
	{
		cin>>mi[i];
	}
	cout<<"\n before sorting\n ";
	for(int i=0;i<x;i++)
	{
		cout<<mi[i];
	}
	mysort(mi, x);
	cout<<"\n\n After sorting\n ";
	for(int i=0;i<x;i++)
	{
		cout<<mi[i];
	}


	return 0;
}