#include<iostream>
using namespace std;

class polar 
{
	int r,teta;
	 static int c;
public:
	polar()
	{
		c++;
	}
	int cnt()
	{
		return c;
	}

};

int polar::c;

int main()
{
	polar p,p2,p3,p4;
	
	 cout<<p.cnt();
	// cout<<p3.cnt();
	return 0;
}