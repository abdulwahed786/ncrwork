#include <iostream>
using namespace std;

class student
{
	int rollno;
	string name;
	 int m1,m2,m3,total;
	string Grade;
public:
	// student(int r,string s,int ma1,int ma2,int ma3,string c)
	// {
	// 	rollno=r;
	// 	name=s;// strcpy()
	// 	m1=ma1; m2=ma2; m3=ma3;
	// 	Grade=c; 
	// }

	friend istream& operator>>(istream &cin,student s);
	friend ostream& operator<<(ostream &cout,student s);	
};

istream& operator>>(istream &cin,student s)
{
	cout<<"enter student details in order:";
	cin>>s.rollno>>s.name>>s.m1>>s.m2>>s.m3;
	s.total=(m1+m2+m3);
	int avg=s.total/3;
		// char g[20];
		if(avg>60)
			s.Grade="first class";
		else if(avg>50 && avg<60)
			s.Grade="second class";
		else if(avg<50 && avg>40)
			s.Grade="third class";
		else
			s.Grade="fail";
		cout<<"done input\n";
		return &cin;
}

ostream& operator<<(istream &out,student s)
{
	cout<<"student details  are :";
	cout<<s.rollno<<" "<<s.name<<" "<<s.m1<<" "<<s.m2<<" "<<s.m3<<" "<<s.total<<" "<<s.Grade;
	cout<<"\n done \n";
		return &cout;
}

int main(int argc, char const *argv[])
{
	student s;
	cin>>s;
	cout<<s;
	return 0;
}