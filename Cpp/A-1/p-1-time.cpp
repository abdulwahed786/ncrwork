// Create a class called Time that has separate int data members for hours, minute, and
// seconds. One constructor should initialize the data to 0, and another should
// initialize it to fixed values. A member function should display it in 11:43:34 format.
// Another member function should add two objects of type Time passed as
// arguments. A main() program should create two initialized Time object and one that
// isn't initialized. Then it should add the two initialized values together, leaving the
// result in the third time variable. Finally, it should display the value of this third
// variable.

#include<iostream>
#include<cstring>
using namespace std;


class time
{
	int hr;
	int min;
	int sec;
   public :
   time()
   {
   	 hr=min=sec=0;
   }
   time(int h,int m,int s)
   {
   	 hr=h; min=m; sec=s;
   }
   void print();
   time add(time t)
   {
   		time r;
   		int s,m,h;
   		s=sec+t.sec;
   		m= s/60 + min + t.min;
   		s=s%60;
   		h=m/60+ hr +t.hr;
   		m=m%60;

   		r.hr=h;
   		r.min=m;
   		r.sec=s; 
   		return r;
   }
};


void time::print()
{
	cout<<"Time :   "<<hr<<":"<<min<<":"<<sec<<endl;
}




int main(int argc, char const *argv[])
{
	int h,m,s;
	cout<<"enter  Time to be added :(hr , min , sec) : ";
	cin>>h>>m>>s;
   time t1(h,m,s);
	t1.print();

	cout<<"enter  Time to be added :(hr , min , sec) : ";
	cin>>h>>m>>s;
   time t2(h,m,s);
	t2.print();

	time t;
   t= t1.add(t2);
	cout<<"Added time : \n";
	t.print();
	
	return 0;
}