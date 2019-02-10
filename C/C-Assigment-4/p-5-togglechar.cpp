#include<iostream>
using namespace std;
#include<string.h>



int main()
{
	char s[10];
	printf(" enter a string\n");
	cin>> s;

	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
		s[i]^=32;
	}

	cout<<"after reverse : "<<s<<endl;
	return 0;
}