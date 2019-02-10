// c-a-5.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
using namespace std;
struct ra
{
	int i;
	char c;
}s;
union ru
{
	int i;
	char c;
}u;

int main()
{
	cout << "\n created a struct and union \n";

	int s1 = sizeof(s);
	int s2 = sizeof(u);

	cout << " size of structure = " << s1 << endl;
	cout << " size of union = " << s2 << endl;

	system("pause");
    return 0;
}

