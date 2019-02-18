#include<iostream>
#include<cstring>
using namespace std;

class student
{
	char *sname;
	char *grade;
	int m1,m2,m3;

public:
	void setdata(char s[],int a1,int a2,int a3)
	{
		strcpy(sname,s);
		m1=a1; m2=a2; m3=a3;
	}
	float calavg()
	{
		return (float)( (m1+m2+m3)/300);
	}
	void computegrade()
	{
		float avg= calavg();
		// char g[20];
		if(avg>60)
			grade="first class";
		else if(avg>50 && avg<60)
			grade="second class";
		else if(avg<50 && avg>40)
			grade="third class";
		else
			grade="fail";

		// strcpy(grade,g);
		// return grade;
	}
	void display()
	{
		cout<<"\n Student name :"<<sname<<endl;
		cout<<"marks :  "<<m1<<" "<<m2<<" "<<m3<<endl;
		cout<<"avgerage :"<<calavg()<<endl;
		cout<<"grade :"<<grade<<endl;
	}

};

int main(int argc, char const *argv[])
{
	char name[10];
	int m1,m2,m3;
	cout<<"enter the student name and marks in three subjects :";
	cin>>name>>m1>>m2>>m3;
	student s;
	s.setdata(name,m1,m2,m3);
	s.computegrade();
	s.display();

	return 0;
}
