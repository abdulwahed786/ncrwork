#include <iostream>
using namespace std; 

struct date
{
	int d;
	int m;
	int y;
}d1,d2;

const int months[]={31,28,31,30,31,30,
	31,31,30,31,30,31};

 int count_leap_yrs(date d)
 {
 	int y=d.y;
 	//check if current year needs to be counted as leap year
 	if(d.m>2)
 		y--;

 	return ( y/4 -y/100 +y/400 );
 }

int main()
{
	cout<<" enter day 1 (dd:mm:yyyy) : "<<endl;
	cin>>d1.d>>d1.m>>d1.y;
	cout<<" enter day 2 (dd:mm:yyyy) : "<<endl;
	cin>>d2.d>>d2.m>>d2.y;

	long long int c1= (365*d1.y)+d1.d;
	for(int i=0;i<d1.m-1;i++)
		c1+=months[i];
	c1+= count_leap_yrs(d1);
	

	long long int c2= (365*d2.y)+d2.d;
	for(int i=0;i<d2.m-1;i++)
		c2+=months[i];
	c2+= count_leap_yrs(d2);

   long long int result=c2-c1;

   cout<<" difference : "<<result;


	return 0;
}
