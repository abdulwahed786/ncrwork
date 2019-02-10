// c-a-5.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include<iostream>
using namespace std;
struct TimeofDay
{
	int hrs;
	int mins;
	int sec;
}s;

int main()
{
	cout << "enter the time of the day : \n";
	cout << " hr:min:sec (format) : ";
	cin >> s.hrs >> s.mins >> s.sec;

	cout << "\n the entered time is : " << s.hrs << ":" << s.mins << ":" << s.sec << endl;
	system("pause");
    return 0;
}

