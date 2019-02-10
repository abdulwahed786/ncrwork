#include<iostream>
using namespace std;
#include<string.h>


void rev(int l,int h, char s[])
{
	if(l>=h)
	  return;
	char t=s[l];
	s[l]=s[h];
	s[h]=t;
	
	rev(l+1,h-1,s);  
}
int main()
{
	char s[10];
	printf(" enter a string\n");
	cin>> s;

	int l=strlen(s);
	rev(0,l-1,s);

	cout<<"after reverse : "<<s<<endl;
	return 0;
}