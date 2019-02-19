#include<iostream>
#include<math.h>
using namespace std;
class Point
{
	int x,y;
	public:
		Point(int m,int n)
		{
			x=m;
			y=n;
		}
		friend double findDistance(const Point &a,const Point &b);
};
double findDistance(const Point &a,const Point &b)
{
	double ans=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	return ans;
}
int main()
{
	Point p1(1,2),p2(2,4);// creating point class objects
	double res=findDistance(p1,p2);
	cout<<"the distance between the two points is "<<res<<endl;
	// to stop console from closing
	system("pause");
	return 0;
}