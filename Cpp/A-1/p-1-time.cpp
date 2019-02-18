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